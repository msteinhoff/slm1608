import sys
import serial
import time
import random

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print "usage: controller.py [serialdevice]"
        sys.exit(-1)

    port = sys.argv[1]
    baud = int(sys.argv[2])
    print "Connecting to %s with %s baud" % (port, baud)

    with serial.Serial(port, baud , timeout=1, dsrdtr=True) as ser:
        print "Connected to %s with %s baud" % (ser.port, ser.baudrate)
        print "Waiting for controller to initialize..."
        time.sleep(2)

        print "Reading welcome message:"
        print ser.read(1024)

        print "Resetting framebuffer:"
        ser.write(b'i')
        print "Result:"
        print ser.read(1024)

        print "Writing green pixels:"
        while True:
            ser.write(b'i')
            for i in range(1024):
                ser.write(random.choice([b'o', b'r', b'g', b'y']))
                ser.flush()
                time.sleep(0.005)
        print "Done"
