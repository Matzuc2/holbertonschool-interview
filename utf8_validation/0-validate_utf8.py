#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify if a data of int is utf8 convertible"""
    for d in data:
        try:
            binary_int = d.to_bytes(1)
            return True
        except OverflowError:
            return False
