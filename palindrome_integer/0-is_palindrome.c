#include <stdio.h>
#include "palindrome.h"

unsigned long reverseDigits(unsigned long num){
    unsigned long rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return(rev_num);
}


int is_palindrome(unsigned long n){
    unsigned long reversed = reverseDigits(n);
    if(reversed == n){
        return(1);
    }else{
        return(0);
    }
}