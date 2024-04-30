// Write a c program to get n number of integers from the user and store them in an array. Now, do 
// the addition and the multiplication of the entire array element and show the results. 0<n<100
#include<stdio.h>
int arr[100];
int main(){
    int i,k,n,sum=0,mul=1;
    printf("Enter your array size: \n");
    scanf("%d",&n);
    printf("Enter your array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    sum=sum+arr[i];
    mul=mul*arr[i];
    }
    printf("The sum of array elements: %d",sum);
    printf("\nThe mul of array elements: %d",mul);

    return 0;
}