#!/usr/bin/python3
"""documented module"""


def validUTF8(data):
    """verify if a data of int is utf8 convertible"""
    if not all(isinstance(item, (int)) for item in data):
        return False
    for i, d in enumerate(data):
        binary_int = bin(d)
        binary_str = split_binary_len9(binary_int)
        decimal_int = int(binary_str, 2)
        if decimal_int > 255:
            return False
        count_of_one = count_byte_expected_number(binary_str)
        if count_of_one > 3:
            return False
        try:
            data[i + count_of_one]
        except IndexError:
            return False
        if count_of_one > 0:
            new_binary_list = []
            new_binary_list.append(binary_str)
            for next_byte_index in range(1, count_of_one):
                next_byte = split_binary_len9(bin(data[i + next_byte_index]))
                new_binary_list.append(next_byte)
                if list(next_byte)[0] != "1":
                    return False
            try:
                dirty_byte = split_binary_len9(bin(data[i + count_of_one + 1]))
                new_binary_list.append(dirty_byte)
                if list(dirty_byte)[0] == "1" and list(dirty_byte[1]) == "0":
                    return False
            except UnboundLocalError and IndexError:
                pass
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
    for i, number in enumerate(list_binary, 0):
        try:
            if i == 0:
                if list_binary[0] == "0":
                    break
                else:
                    pass
            elif list_binary[i] == "0":
                break
            elif list_binary[i] == "1":
                count_of_one += 1
        except IndexError:
            return count_of_one
    return count_of_one


def is_byte_legit(byte: int, data: list[int]):
    index_byte = data.index(byte)
    for i, item in enumerate(data):
        if i < index_byte and data[i] != data[index_byte]:
            data.pop(i)
    binary_int = bin(byte)
    binary_str = split_binary_len9(binary_int)
    count_byte_number = count_byte_expected_number(binary_str)
