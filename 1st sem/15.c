// C program to check whether a number is palindrome or not
#include <stdio.h>

int main()
{
    int original_number;
    printf("Enter the number you wanted palindrome: \n");
    scanf("%d", &original_number);

    int reversed = 0;

    int num = original_number;

    while (num != 0)
    {
        int r = num % 10;
        reversed = reversed * 10 + r;
        num /= 10;
    }

    if (original_number == reversed)
    {
        printf(" Given number %d is a palindrome number",
               original_number);
    }
    else
    {
        printf(
            " Given number %d is not a palindrome number",
            original_number);
    }

    return 0;
}