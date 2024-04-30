// calculation of cube and sqrt without math library function

#include <stdio.h>
float cube(float n)
{
    return n * n * n;
}
double sqroot(double square)
{
    double root = square / 3;
    float k;
    int i;
    if (square <= 0)
        return 0;
    for (i = 0; i < 80; i++)
        root = (root + square / root) / 2;
    return root;
}
int main()
{
    float l, j, k;
    printf("Enter the number to  calculate cube: \n");
    scanf("%f", &j);
    printf("Th cube of number: %f", cube(j));
    printf("\nEnter the number to calculate square root(within 80): \n");
    scanf("%f", &k);
    printf("The square root of number: %lf", sqroot(k));
    return 0;
}