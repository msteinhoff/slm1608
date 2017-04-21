import sys
import time
import argparse
import logging
import serial

import driver
import generators

logging.basicConfig(stream=sys.stdout, level=logging.INFO)
logger = logging.getLogger('controller')

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("port", help="The serial device to use")
    parser.add_argument("--baud", type=int, default=115200, help="The symbol rate to use")
    parser.add_argument("--loop", action="store_true", help="If the frames should be looped infinitely")
    subparsers = parser.add_subparsers(dest="pixelgenerator")
    staticframes_parser = subparsers.add_parser('staticframes')
    stripes_parser = subparsers.add_parser('stripes')
    gif_parser = subparsers.add_parser('gif')
    gif_parser.add_argument('filename')
    return parser.parse_args()

def build_frames(args):
    if args.pixelgenerator == 'staticframes':
        frames = generators.staticframes.create_frames()
        logger.info("Loaded %s static frames", len(frames))
    elif args.pixelgenerator == 'stripes':
        frames = generators.stripes.create_frames()
        logger.info("Loaded %s frames for stripe animation", len(frames))
    elif args.pixelgenerator == 'gif':
        frames = generators.gif.create_frames(args.filename)
        logger.info("Loaded %s frames from gif '%s'", len(frames), args.filename)
    else:
        raise ValueError("unknown pixel generator %s", args.pixelgenerator)
    return frames

def write_frames_once(driver, frames):
    logger.info("Writing animation with %s frames to display driver (press ctrl+c to abort)", len(frames))
    start = time.time()
    count = 0
    try:
        for frame in frames:
            driver.write_frame(frame)
            count += 1
    except KeyboardInterrupt:
        pass
    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))

def write_frames_looped(driver, frames):
    logger.info("Writing animation with %s frames to display driver, looped infinitely (press ctrl+c to abort)", len(frames))
    start = time.time()
    count = 0
    while True:
        try:
            for frame in frames:
                driver.write_frame(frame)
                time.sleep(0.09)
                count += 1
                if count % 32 == 0:
                    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))
        except KeyboardInterrupt:
            break
    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))

if __name__ == "__main__":
    args = parse_args()
    frames = build_frames(args)
    drv = driver.LEDMatrixDriver()
    try:
        drv.connect(args.port, args.baud)
        if not args.loop:
            write_frames_once(drv, frames)
        else:
            write_frames_looped(drv, frames)            
    finally:
        drv.disconnect()
