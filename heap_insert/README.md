# Heap Insert - Binary Tree Implementation

This project implements binary tree node creation and manipulation as part of the Holberton School interview preparation.

## Project Structure

- `binary_trees.h` - Header file containing structure definitions and function prototypes
- `0-binary_tree_node.c` - Implementation of binary tree node creation
- `0-main.c` - Main test file demonstrating tree creation and printing
- `binary_tree_print.c` - Utility function for visualizing binary trees

## Data Structure

```c
typedef struct binary_tree_s
{
    int n;                          // Integer stored in the node
    struct binary_tree_s *parent;   // Pointer to the parent node
    struct binary_tree_s *left;     // Pointer to the left child node
    struct binary_tree_s *right;    // Pointer to the right child node
} binary_tree_t;
```

## Functions

### `binary_tree_node`
Creates a new binary tree node with a given value and parent.

**Prototype:**
```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

**Parameters:**
- `parent` - Pointer to the parent node (or NULL for root)
- `value` - Integer value to store in the node

**Returns:**
- Pointer to the newly created node
- NULL on failure

## Compilation

Compile the program with:
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
```

## Usage

Run the compiled program:
```bash
./0-node
```

This will create a binary tree with the following structure:
```
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```

## Requirements

- Ubuntu/Linux environment
- GCC compiler
- All files compiled with `-Wall -Wextra -Werror -pedantic`

## Author

Holberton School Interview Preparation Project
