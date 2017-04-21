import time
import serial
import logging
import struct

logger = logging.getLogger('driver')

class LEDMatrixDriver():
    def __init__(self):
        self.connection = None

    def connect(self, port, baud=115200):
        """
        Connects to the display driver over a serial port and waits for the
        driver to fully initialize.
        """
        logger.info("Opening serial port '%s' with %s baud", port, baud)
        self.connection = serial.Serial(port, baud, dsrdtr=True)

        logger.info("Waiting for display driver to initialize...")
        start = time.time()
        self.connection.timeout = 3
        self.__expect_ascii_data(b'<Arduino is ready>')
        self.connection.timeout = None
        logger.info("Display driver initialized in %s seconds.", round(time.time()-start,3))

    def write_frame(self, frame):
        logger.debug("Writing frame with %s bytes", len(frame))
        begin_start = time.time()
        self.__write(b'\x3C')
        begin_duration = time.time() - begin_start
        logger.debug("Written start byte, took %s", round(begin_duration,10))

        data_start = time.time()
        # this optimization yiels 1-2 more frames per second but for this we
        # have to change all pixel generators to deliver integers
        #bytes = struct.pack('=%sB' % len(frame), *frame)
        #count = len(bytes)
        #self.__write(bytes)
        count = 0
        for byte in frame:
            self.__write(byte)
            count += 1
        data_duration = time.time() - data_start
        logger.debug("Written %s bytes, took %s", count, round(data_duration,4))

        end_start = time.time()
        self.__write(b'\x3E')
        end_duration = time.time() - end_start
        logger.debug("Written end byte, took %s", round(end_duration,10))
        logger.debug("Written frame, took %s", round(time.time() - begin_start,4))

    def __expect_ascii_data(self, expected):
        # +2 to account for \r\n
        expected_size = len(expected)+2
        logger.debug("Expecting string %s (%s bytes) on serial port", expected, expected_size)
        data = self.connection.read(expected_size)
        data = data.strip()
        if data != expected:
            raise ValueError("Expected {} but got {}".format(expected, data))
        logger.debug("Received data: '%s'", data)
        return data

    def __write(self, data):
        self.connection.write(data)

    def __write_with_ack(self, data, expected):
        self.connection.write(data)
        ack = self.connection.read(len(expected)+2).strip() # +2 to account for \r\n
        if ack != expected:
            # edge case: error-underrun will also transmit the number bytes in
            # the received buffer
            if ack == 'eur':
                logger.error("error-underrun: received %s bytes", self.connection.read(6))
                pass
            raise ValueError("Expected {} but got {}".format(expected, ack))

    def disconnect(self):
        if self.connection != None:
            self.connection.close()
        logger.info("Disconnected from display driver.")
