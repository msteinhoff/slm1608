import logging

logger = logging.getLogger("stripes")

def create_argparser(subparsers):
    gif_parser = subparsers.add_parser('stripes')

def create_frames_from_args(args):
    frames = create_frames()
    logger.info("Loaded %s frames for stripe animation", len(frames))
    return frames

def create_frames():
    frames = []

    for x in range(15):
        frame = [b'\x00'] * 256
        frame[x] = b'\xFF'
        frame[x+128] = b'\xFF'
        frames.append(frame)

    return frames
