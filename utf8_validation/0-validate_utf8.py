#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify if a data of int is utf8 convertible"""
    for i, d in enumerate(data):
        binary_int = bin(d)
        # print(f"{binary_int}, binary_int")
        binary_str = split_binary_len9(binary_int)
        # print(f"{binary_str}, binary_str")
        decimal_int = int(binary_str, 2)
        # print(f"{decimal_int} decimal int")
        if decimal_int > 255:
            return False
        count_of_one = count_byte_expected_number(binary_str)
        # print(count_of_one)
        try:
            data[i + count_of_one]
        except IndexError:
            return False
        if count_of_one > 0:
            for next_byte_index in range(0, count_of_one):
                next_byte = split_binary_len9(bin(data[i + next_byte_index]))
                if list(next_byte)[0] != "1":
                    return False
    return True


def split_binary_len9(binary_str: str):
    new_binary_str = binary_str.replace('0b', '')
    binary_split = list(new_binary_str)
    if len(new_binary_str) > 8:
        for i, number in enumerate(binary_split):
            if len(binary_split) == 8:
                break
            else:
                binary_split.pop(0)
        new_str_binary = "".join(binary_split)
        return new_str_binary
    elif len(new_binary_str) < 8:
        for i, number in enumerate(binary_split):
            if len(new_binary_str) == 8:
                break
            else:
                new_binary_str = "".join(('0' + new_binary_str))
        return new_binary_str
    else:
        return new_binary_str


def count_byte_expected_number(binary_str: str):
    count_of_one = 0
    list_binary = list(binary_str)
    for i, number in enumerate(list_binary):
        try:
            if list_binary[i] == "0":
                return count_of_one
            elif list_binary[i] == "1":
                count_of_one += 1
        except IndexError:
            return count_of_one
    return count_of_one
