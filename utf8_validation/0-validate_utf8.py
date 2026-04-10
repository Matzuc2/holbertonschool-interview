#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify is a data of int is utf8 convertible"""
    try:
        for d in data:
            if d > 255:
                return False
        return True
    except ValueError:
        return False
