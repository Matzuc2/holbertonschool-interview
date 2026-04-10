#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify if a data of int is utf8 convertible"""
    try:
        for d in data:
            bin_int = bin(d)
            list_bin_str = list(bin_int)
            if len(list_bin_str) > 9:
                return False
        return True
    except ValueError:
        return False
