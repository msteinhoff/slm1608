def create_frames(ser):
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
