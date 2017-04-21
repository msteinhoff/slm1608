import sys
import argparse
import logging

import driver
import animation
import generators

logging.basicConfig(stream=sys.stdout, level=logging.INFO)

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("port", help="The serial device to use")
    parser.add_argument("--baud", type=int, default=115200, help="The symbol rate to use")
    parser.add_argument("--fps", type=int, default=15, help="How many frames per second to send")
    parser.add_argument("--loop", action="store_true", help="If the frames should be looped infinitely")
    subparsers = parser.add_subparsers(dest="pixelgenerator")
    generators.staticframes.create_argparser(subparsers)
    generators.stripes.create_argparser(subparsers)
    generators.gif.create_argparser(subparsers)
    return parser.parse_args()

def build_frames(args):
    if args.pixelgenerator == 'staticframes':
        frames = generators.staticframes.create_frames_from_args(args)
    elif args.pixelgenerator == 'stripes':
        frames = generators.stripes.create_frames_from_args(args)
    elif args.pixelgenerator == 'gif':
        frames = generators.gif.create_frames_from_args(args)
    else:
        raise ValueError("unknown pixel generator %s", args.pixelgenerator)
    return frames

if __name__ == "__main__":
    args = parse_args()
    frames = build_frames(args)
    drv = driver.LEDMatrixDriver()
    try:
        drv.connect(args.port, args.baud)
        if args.loop:
            animation.write_frames_looped(drv, frames, args.fps)
        else:
            animation.write_frames_once(drv, frames, args.fps)
    finally:
        drv.disconnect()
