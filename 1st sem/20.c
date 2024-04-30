//Write a progrm to find out area and perimeter of a rectangle using two diff functions

#include<stdio.h>
int area(int w, int h){
    return w*h;
}
int perimeter(int w, int h){
    return 2*(w+h);
}
       
int main(){
    int a,b;
     printf("Enter the height of recatngle: \n");
    scanf("%d",&a);
    printf("Enter the width of rectangle: \n");
    scanf("%d", &b);
    printf("The area: %d", area(a,b));
    printf("\nThe perimeter: %d", perimeter(a,b));
    return 0;
}