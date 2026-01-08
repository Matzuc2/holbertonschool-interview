#include <stdlib.h>
#include "lists.h"

listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head pointer
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast;
    listint_t *second_half, *first_half;

    if (!head || !*head || !(*head)->next)
        return 1; /* empty or 1 node list */

    slow = *head;
    fast = *head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_list(slow);
    first_half = *head;

    while (second_half)
    {
        if (first_half->n != second_half->n)
            return 0;

        first_half = first_half->next;
        second_half = second_half->next;
    }

    return 1;
}