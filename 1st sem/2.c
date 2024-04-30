//swaping two numbers by using third variables

#include<stdio.h>
int main(){
    int a,b,temp;
    printf("Enter the value of a and b: \n");
    scanf("%d%d",&a,&b);
    temp=a;
    a=b;
    b=temp;
    printf("The value of a and b is: %d and %d", a,b);
    return 0;
}

//swaping two numbers without using third variables

#include<stdio.h>
void swap(){
    int i,j;
    printf("Enter the values of i and j: \n");
    scanf("%d%d",&i,&j);
    i=i^j;
    j=i^j;
    i=i^j;
    printf("The values of i and j is: %d and %d", i,j);
    return 0;
}