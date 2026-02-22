# Sandpiles

## Description

This project implements a function that computes the sum of two sandpiles. A sandpile is represented as a 3x3 grid of integers. A sandpile is considered **stable** when none of its cells contains more than 3 grains.

When two sandpiles are added together, the result may be unstable. The algorithm stabilizes the sandpile through a process called "toppling":
- Any cell with more than 3 grains distributes 4 grains to its 4 neighbors (up, down, left, right)
- The cell loses 4 grains in the process
- This process repeats until the entire sandpile becomes stable

## Files

- `sandpiles.h` - Header file containing the function prototype
- `0-sandpiles.c` - Implementation of the sandpiles sum algorithm
- `0-main.c` - Test file with example requiring multiple toppling rounds
- `1-main.c` - Test file with example that results in a stable sandpile

## Function Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

## Requirements

- No dynamic memory allocation allowed
- Both input grids are individually stable
- After execution, `grid1` contains the stable sum
- The grid is printed before each toppling round (only if unstable)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 1-sandpiles
```

## Usage

### Example 1: Unstable Result (Multiple Toppling Rounds)

```bash
./0-sandpiles
```

**Input:**
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
```

**Output:**
```
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

### Example 2: Stable Result (No Toppling)

```bash
./1-sandpiles
```

**Input:**
```
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
```

**Output:**
```
=
3 3 3
3 3 3
3 3 3
```

## Algorithm

1. Add `grid2` to `grid1` element-wise
2. Check if the result is stable (all cells ≤ 3)
3. If unstable:
   - Print the current state
   - Identify all cells with value > 3
   - For each unstable cell:
     - Subtract 4 from the cell
     - Add 1 to each neighbor (top, bottom, left, right)
   - Repeat until stable

## Author

Holberton School Interview Preparation Project
