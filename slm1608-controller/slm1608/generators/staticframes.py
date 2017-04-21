import logging

logger = logging.getLogger("staticframes")

def create_argparser(subparsers):
    gif_parser = subparsers.add_parser('staticframes')

def create_frames_from_args(args):
    frames = create_frames()
    logger.info("Loaded %s static frames", len(frames))
    return frames

def create_frames():
    return [
        [
            b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55',     b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55', 
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55',     b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55',
        ],
        [
            b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55',     b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55', 
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\xFF', b'\x00',    b'\x00', b'\xFF', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\xFF', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x40', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x00',     b'\x00', b'\x00', b'\x00', b'\x00',    b'\x00', b'\x00', b'\x00', b'\x01',
            b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55',     b'\x55', b'\x55', b'\x55', b'\x55',    b'\x55', b'\x55', b'\x55', b'\x55'
        ],
    ]
