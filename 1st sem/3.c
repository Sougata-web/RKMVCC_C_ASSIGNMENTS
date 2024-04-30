//size of int,float,char,double

#include<stdio.h>
int main(){
    int a;
    float b;
    char c;
    double d;
    printf("The size of int is: %lu\n", sizeof(a));
    printf("The size of float is: %lu\n", sizeof(b));
    printf("The size of char is: %lu\n", sizeof(c));
    printf("The size of double is: %lu\n", sizeof(d));
    return 0;
}