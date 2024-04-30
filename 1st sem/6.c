// Write a c program to find largest number among three numbers using ternary operator and 
// smallest among them using nested if-else

#include<stdio.h>
int main(){
    int n1,n2,n3,max,min;
    printf("Enter three numbers: \n");
    scanf("%d%d%d",&n1,&n2,&n3);
    max=(n1>n2)?(n1>n3?n1:n3):(n2>n3?n2:n3);
    printf("Largest number of them is: %d", max);
    
    return 0;
}