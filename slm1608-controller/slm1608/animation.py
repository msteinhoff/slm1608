import time
import logging

logger = logging.getLogger("animation")

def write_frames_once(driver, frames, framerate):
    logger.info("Writing animation with %s frames to display driver (press ctrl+c to abort)", len(frames))
    start = time.time()
    count = 0
    try:
        for frame in frames:
            driver.write_frame(frame)
            count += 1
            time.sleep(1/framerate)
    except KeyboardInterrupt:
        pass
    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))

def write_frames_looped(driver, frames, framerate):
    logger.info("Writing animation with %s frames to display driver, looped infinitely (press ctrl+c to abort)", len(frames))
    start = time.time()
    count = 0
    while True:
        try:
            for frame in frames:
                driver.write_frame(frame)
                time.sleep(1/framerate)
                count += 1
                if count % 32 == 0:
                    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))
        except KeyboardInterrupt:
            break
    logger.info("Written %s frames (%s fps)", count, count/(time.time()-start))
