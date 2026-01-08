#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    Calculates the minimum number of operations to reach exactly n 'H'
    characters using only Copy All and Paste.

    Args:
        n (int): target number of characters

    Returns:
        int: minimum number of operations, or 0 if impossible
    """
    if n <= 1:
        return 0

    ops = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            ops += factor
            n //= factor
        factor += 1

    return ops