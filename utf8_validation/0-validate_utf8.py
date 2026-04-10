#!/usr/bin/python3
def validUTF8(data):
    try:
        byte_data = bytearray(data)
        return True
    except ValueError:
        return False
