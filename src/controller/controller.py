import sys
import serial
import time

framebuffer = bytearray([0] * 1024)
counter = 0

def updateFramebuffer():
    global framebuffer
    global counter
    framebuffer[counter] = 0x01
    counter += 1
    if counter > 1024:
        framebuffer = bytearray([0] * 1024)
        counter = 0

def printFramebuffer():
    print "hi"
    for index, byte in enumerate(framebuffer):
        print byte,
        if (index > 0 and index % 64 == 0):
            print "x"

def writeFramebuffer(ser):
    for byte in framebuffer:
        ser.write(byte)

if __name__ == "__main__":
    #/dev/tty.usbmodem641
    if len(sys.argv) != 2:
        print "usage: controller.py [serialdevice]"
        sys.exit(-1)

    print "printing pixels to %s" % (sys.argv[1])
    with serial.Serial(sys.argv[1], 38400, timeout=1) as ser:
        while True:
            # update framebuffer
            updateFramebuffer()
            print "dot"

            printFramebuffer()

            # write framebuffer
            writeFramebuffer(ser)
            print "write"

            # limit framerate
            time.sleep(0.1)
