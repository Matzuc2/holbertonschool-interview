#include <stdio.h>
#include "palindrome.h"

/**
 * reverseDigits - reverses the digits of a number
 * @num: number to reverse
 *
 * Return: reversed number
 */
unsigned long reverseDigits(unsigned long num)
{
    unsigned long rev_num = 0;

    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return (rev_num);
}

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = reverseDigits(n);

    if (reversed == n)
        return (1);
    return (0);
}
