import sys
import serial
import time
import random

def write_two_frames_in_loop(ser):
    frames = [
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
    while True:
        for frame in frames:
            write_frame(ser, frame)

def write_sliding_strips(ser):
    while True:
        frame = [b'\x00'] * 256
        x = 0
        last_x = 0

        while True:
            if x > 15:
                break

            frame[x] = b'\xff'
            frame[x+128] = b'\xff'
            x += 1

            write_frame(ser, frame)

            if x > 0:
                frame[last_x] = b'\x00'
                frame[last_x+128] = b'\x00'
                last_x = x
            #time.sleep(0.05)

def write_frame(ser, frame):
    #send_with_ack(ser, b'\x3C', "beg")
    send(b'\x3C')

    for bt in frame:
        send(ser, bt)

    #send_with_ack(ser, b'\x3E', "end")
    send(ser, b'\x3E')

def write_frame_timed(ser, frame):
    start1 = time.time()
    #send_with_ack(ser, b'\x3C', "beg")
    send(b'\x3C')

    start2 = time.time()
    cnt = 0
    for bt in frame:
        send(ser, bt)
        cnt += 1
    end2 = time.time()

    #send_with_ack(ser, b'\x3E', "end")
    send(ser, b'\x3E')
    end1 = time.time()
    print "Written frame data (%s bytes, frame in %s, data in %s)" %(cnt, end1-start1, end2-start2)

def send(ser, data):
    ser.write(data)

def send_with_ack(ser, data, expected):
    ser.write(data)
    ack = ser.read(len(expected)+2) # +2 to account for \r\n
    if ack.strip() != expected:
        if ack.strip() == 'eur':
            print "error-underrun: received %s bytes" % ser.read(6)
        raise ValueError("Expected %s ack but got %s" % (expected, ack.strip()))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print "usage: controller.py [serialdevice]"
        sys.exit(-1)

    port = sys.argv[1]
    baud = int(sys.argv[2])
    print "Connecting to %s with %s baud" % (port, baud)



    with serial.Serial(port, baud) as ser:
    #with serial.Serial(port, baud , timeout=None, dsrdtr=False) as ser:
        print "Waiting for controller to initialize..."
        welcomemsg = ser.read(20) # expected: <Arduino is ready>\r\n
        print "Received welcome message: %s" % (welcomemsg)

        print "Writing pixel data..."
        #write_two_frames_in_loop(ser)
        write_sliding_strips(ser)

        print "Done"

