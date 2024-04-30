//Write a c program to check whether a given number is even or odd.

#include<stdio.h>
int main(){
    int i;
    printf("Enter any number: \n");
    scanf("%d", &i);
    if(i%2==0){
        printf("It's a even number.");
    }
    else{
        printf("It's a odd number.");
    }
    return 0;
}