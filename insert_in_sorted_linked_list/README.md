# Insert in Sorted Linked List

This project provides a function to insert a number into a sorted singly linked list of integers in ascending order.

## Files

- `0-insert_number.c`: Contains the implementation of the `insert_node` function.
- `lists.h`: Header file with the definition of the linked list structure and function prototypes.

## Function

### `listint_t *insert_node(listint_t **head, int number);`

Inserts a new node with a given integer into a sorted singly linked list so that the list remains sorted in ascending order.

#### Parameters
- `head`: Double pointer to the head of the linked list.
- `number`: The integer value to insert.

#### Return Value
- Returns the address of the new node, or `NULL` if it failed.

## Data Structure

```
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Usage

1. Compile the code:
   ```bash
   gcc 0-insert_number.c main.c -o insert_number
   ```
2. Run your program:
   ```bash
   ./insert_number
   ```

## Author
- [Your Name]
