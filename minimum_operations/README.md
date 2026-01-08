# Minimum Operations

## Description

This project implements a solution to calculate the minimum number of operations needed to result in exactly `n` `H` characters in a text file, starting with a single `H` character. The only available operations are:
- **Copy All**: Copy all characters currently in the file
- **Paste**: Paste the copied characters

## Algorithm

The solution uses a **prime factorization** approach:
- For a given number `n`, the minimum operations equals the sum of its prime factors
- This works because each prime factor represents an optimal sequence of copy and paste operations
- The algorithm iteratively divides `n` by its smallest factors and accumulates the operation count

## Files

- [0-minoperations.py](0-minoperations.py) - Contains the `minOperations(n)` function
- [0-main.py](0-main.py) - Test file demonstrating the function usage

## Function Prototype

```python
def minOperations(n):
```

## Parameters

- `n` (int): Target number of `H` characters

## Returns

- `int`: Minimum number of operations needed, or `0` if impossible (n ≤ 1)

## Example

```python
n = 4
print(minOperations(n))  # Output: 4
# Explanation: H => Copy All => Paste => HH => Copy All => Paste => Paste => HHHH

n = 12
print(minOperations(n))  # Output: 7
# Explanation: 12 = 2 × 2 × 3, so operations = 2 + 2 + 3 = 7
```

## Usage

```bash
./0-main.py
```

## Requirements

- Python 3.x
- Code follows PEP 8 style guide (pycodestyle)