#include <stdio.h>
int main()
{
    char str[1000], reverse[1000];
    int i, strIndex, revIndex, len;
    printf("Enter any string: ");
    fgets(str, 1000, stdin);
    i = 0;
    while (str[i] != '\0')
        i++;
    len = i;
    revIndex = 0;
    strIndex = len - 1;
    while (strIndex >= 0)
    {
        reverse[revIndex] = str[strIndex];
        strIndex--;
        revIndex++;
    }
    reverse[revIndex] = '\0';
    printf("\nOriginal string = %s", str);
    printf("Reverse string = %s", reverse);
    return 0;
}
