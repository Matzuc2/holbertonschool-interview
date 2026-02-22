# Linked List Cycle

## Description
This project implements a function in C that detects if a singly linked list has a cycle in it. A cycle occurs when a node's next pointer points back to a previous node in the list, creating a loop.

## Algorithm
The solution uses **Floyd's Cycle Detection Algorithm** (also known as the "tortoise and hare" algorithm):
- Uses two pointers: `slow` (moves one step at a time) and `fast` (moves two steps at a time)
- If there's a cycle, the fast pointer will eventually catch up to the slow pointer
- If there's no cycle, the fast pointer will reach the end (NULL)

## Complexity
- **Time Complexity:** O(n) - where n is the number of nodes
- **Space Complexity:** O(1) - no extra memory allocations needed

## Files
- `lists.h` - Header file with structure definition and function prototypes
- `0-check_cycle.c` - Implementation of the cycle detection function
- `0-linked_lists.c` - Helper functions for linked list operations
- `0-main.c` - Test file

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Usage
```bash
./cycle
```

## Expected Output
```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Function Prototype
```c
int check_cycle(listint_t *list);
```

**Parameters:**
- `list` - pointer to the head of the linked list

**Return:**
- `0` if there is no cycle
- `1` if there is a cycle

## Requirements
- Only these functions are allowed: write, printf, putchar, puts, malloc, free
- All files compiled on Ubuntu with gcc using flags: -Wall -Werror -Wextra -pedantic
