// Write a c program to print the day of 1st January of any year inputted by the user, considering the
// first January of 1900 is Monday.

#include <stdio.h>
int main()
{
    int y, a, d, i, flag = 0;

    printf("Enter a year: ");
    scanf("%d", &y);

    a = y - 1900;

    if (a >= 0)
        a = a;
    else
    {
        a = -a;
        flag = 1;
    }

    if (flag == 1)
        a = a * 365;
    else
    {
        if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
            a = (a * 365) - 1;
        else
            a = a * 365;
    }

    if (flag == 1)
    {
        for (i = y; i <= 1900; i++)
        {
            if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
                a++;
        }
    }
    else
    {
        for (i = 1900; i <= y; i++)
        {
            if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
                a += 1;
        }
    }
    d = a % 7;

    if (flag == 1)
    {
        switch (d)
        {
        case 0:
            printf("1st January of %d is Monday", y);
            break;
        case 1:
            printf("1st January of %d is Sunday", y);
            break;
        case 2:
            printf("1st January of %d is Saturday", y);
            break;
        case 3:
            printf("1st January of %d is Friday", y);
            break;
        case 4:
            printf("1st January of %d is Thursday", y);
            break;
        case 5:
            printf("1st January of %d is Wednesday", y);
            break;
        case 6:
            printf("12st January of %d is Tuesday", y);
            break;
        default:
            printf("Error 101");
            break;
        }
    }
    else
    {
        switch (d)
        {
        case 0:
            printf("1st January of %d is Monday", y);
            break;
        case 1:
            printf("1st January of %d is Tuesday", y);
            break;
        case 2:
            printf("1st January of %d is Wednesday", y);
            break;
        case 3:
            printf("1st January of %d is Thursday", y);
            break;
        case 4:
            printf("1st January of %d is Friday", y);
            break;
        case 5:
            printf("1st January of %d is Saturday", y);
            break;
        case 6:
            printf("12st January of %d is Sunday", y);
            break;
        default:
            printf("Error 101");
            break;
        }
    }
    return 0;
}