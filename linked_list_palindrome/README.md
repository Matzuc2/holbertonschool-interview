# Linked List Palindrome

## Description
This project implements a function to check if a singly linked list is a palindrome. A palindrome is a sequence that reads the same forwards and backwards.

## Requirements
- Ubuntu 14.04 LTS or later
- GCC compiler
- Allowed editors: vi, vim, emacs
- All files should end with a new line
- Code should follow the Betty style

## Files
- [lists.h](lists.h) - Header file containing structure definitions and function prototypes
- [0-is_palindrome.c](0-is_palindrome.c) - Implementation of the palindrome checking function

## Function Prototype
```c
int is_palindrome(listint_t **head);
```

## Algorithm
The function uses the **two-pointer technique** to efficiently check if a linked list is a palindrome:

1. **Find the middle**: Uses slow and fast pointers to locate the middle of the list
   - Slow pointer moves one step at a time
   - Fast pointer moves two steps at a time
   - When fast reaches the end, slow is at the middle

2. **Reverse the second half**: Reverses the second half of the linked list

3. **Compare halves**: Compares the first half with the reversed second half
   - If all values match, the list is a palindrome
   - If any value differs, it's not a palindrome

## Time and Space Complexity
- **Time Complexity**: O(n) - where n is the number of nodes
- **Space Complexity**: O(1) - only uses a constant amount of extra space

## Return Value
- `1` if the linked list is a palindrome
- `0` if the linked list is not a palindrome
- `1` for empty lists or lists with a single node

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-is_palindrome.c -o palindrome
```

## Usage Example
```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    
    /* Create list: 1 -> 2 -> 3 -> 2 -> 1 */
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);
    
    if (is_palindrome(&head))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    
    free_listint(head);
    return (0);
}
```

## Author
Holberton School Interview Preparation Project
