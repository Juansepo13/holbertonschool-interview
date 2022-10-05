#!/usr/bin/python3
"""
0. UTF-8 Validation
"""


def validUTF8(data):
    """
    0. UTF-8 Validation
    Return: True if data is a valid UTF-8 encoding, else return False
    - A character in UTF-8 can be 1 to 4 bytes long
    - The data set can contain multiple characters
    - The data will be represented by a list of integers
    - Each integer represents 1 byte of data, therefore you only need to
    handle the 8 least significant bits of each integer
    """

    successive_10 = 0
    for b in data:
        # b = bin(b).replace('0b', '').rjust(8, '0')[-8:]
        b = format(b, '#010b')[-8:]
        if successive_10 != 0:
            successive_10 -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
            successive_10 = len(b.split('0')[0])
            if successive_10 == 1 or successive_10 > 4:
                return False
            successive_10 -= 1

    return True if successive_10 == 0 else False
