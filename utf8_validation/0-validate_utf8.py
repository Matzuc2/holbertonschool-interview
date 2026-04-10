#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify is a data of int is utf8 convertible"""
    try:
        byte_data = bytearray(data)
        return True
    except ValueError:
        return False
