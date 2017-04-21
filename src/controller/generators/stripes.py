def create_frames():
    frames = []

    for x in range(15):
        frame = [b'\x00'] * 256
        frame[x] = b'\xFF'
        frame[x+128] = b'\xFF'
        frames.append(frame)

    return frames
