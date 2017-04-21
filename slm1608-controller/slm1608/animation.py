import logging
import time

logger = logging.getLogger('animation')

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
