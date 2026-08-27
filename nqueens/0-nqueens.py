#!/usr/bin/python3

import sys

args = sys.argv
if len(args) != 2:
    print('Usage nqueens N')
    exit(1)
n = args[1]
try:
    int(args[1])
except ValueError:
    print('N must be a number')
    exit(1)

if int(n) < 4:
    print('N must be at least 4')
    exit(1)


def solve(line, n, queens):
    if line == n:
        print(queens)
        return
    for column in range(n):
        if is_queen_safe(line, column, queens):
            queens.append([line, column])
            solve(line + 1, n, queens)
            queens.pop()


def is_queen_safe(line, column, queens):
    new_queen_pos = line + column
    new_queen_neg = line - column
    is_safe = True
    for queen in queens:
        queen_pos = queen[0] + queen[1]
        queen_neg = queen[0] - queen[1]
        if queen_neg == new_queen_neg or queen_pos == new_queen_pos or queen[1] == column:
            is_safe = False
    return is_safe


solve(0, int(n), [])

