import struct
from PIL import Image

def create_frames(filename):
    with Image.open(filename) as im:
        frames = convert_gif_to_frames(im)

    return frames
    
def convert_gif_to_frames(image):
    frames = []

    # TODO make sure that the image has 64x16px (raise error or resize)
    while True:
        bw_im = image.convert('L')

        bit_frame = create_bit_frame(bw_im)
        byte_frame = pack_bit_frame(bit_frame)
        frames.append(byte_frame)
        
        try:
            image.seek(image.tell() + 1)
        except EOFError:
            break

    return frames

def create_bit_frame(image):
    '''
    Create a frame array from a loaded PIL image. The frame array contains 1024
    elements where each element is a 2-bit value that represents a pixel (red
    and green).
    '''
    bit_frame = []

    for y in range(image.size[1]):
        for x in range(image.size[0]):
            value = image.getpixel((x, y))
            bit_value = map_pixel_value(value)
            bit_frame.append(bit_value)

    return bit_frame

def map_pixel_value(pixel_value):
    '''
    The image is converted to a black/white image with 8 bits per pixel. The LED
    matrix display can only show 2 bits per pixel (off, red, green or yellow) so
    the 8 bit value must be mapped:
    
       8 bits | 2 bits
    ----------+----------------
            0 | 0x00 (off)
      1 -  85 | 0x02 (red)
     86 - 170 | 0x01 (green)
    171 - 255 | 0x03 (yellow)
    '''
    # off
    if pixel_value == 0:
        return 0

    # red - 0x10
    elif 1 <= pixel_value <= 85:
        return 0

    # green - 0x01
    elif 86 <= pixel_value <= 170:
        return 0

    # yellow - 0x11
    elif 171 <= pixel_value <= 255:
        return 1

    # lol
    else:
        raise ValueError("can not map pixel value {}".format(pixel_value))

def pack_bit_frame(frame):
    '''
    Before a frame can be transmitted to the LED driver, it must be packed for
    efficiency. A gif frame with 1024 2 bit elements will be converted into a
    driver frame with 256 8 bit elements, and each element stores the values of
    four pixels.
    '''
    byte_frame = []
    chunksize = 4

    for i in range(0,len(frame),chunksize):
        byte = pack_four_pixels(frame[i:i+chunksize])
        byte_frame.append(byte)

    return byte_frame

def pack_four_pixels(pixels):
    value = 0
    value |= (pixels[0] << 6)
    value |= (pixels[1] << 4)
    value |= (pixels[2] << 2)
    value |= (pixels[3] << 0)
    # need to deliver bytes
    return struct.pack('=B',value)
