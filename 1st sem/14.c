// C Program to Display Armstrong
// numbers between 1 to 1000
#include <stdio.h>
#include <math.h>
 
int main()
{
    int i, digit1, digit2, digit3, sum, num;
    printf("All Armstrong number between 1 and 1000 are:\n");
 
    for (i = 1; i <= 1000; i++)
    {
        num = i;
        if (num <= 9)
        {
            printf("%d ", num);
        }
        else
        {
            sum = pow(num % 10, 3) + pow((num % 100 - num % 10) / 10, 3) + pow((num % 1000 - num % 100) / 100, 3);
            if (sum == i)
            {
                printf("%d ", i);
            }
        }
    }
}