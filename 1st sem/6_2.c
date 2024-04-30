//Lowest number among three words

#include<stdio.h>
int main(){
    int n1,n2,n3,min;
     printf("Enter three numbers: \n");
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n1<n2){
        if(n1<n3){
            printf("The lowest number is: %d", n1);
        }
        else{
            printf("The lowest number is: %d", n3);
        }
    }
    else{
        if(n2<n1){
            printf("The lowest number is: %d", n2);
        }
        else{
            printf("The lowest number is: %d", n3);
        }
    }
    return 0;
}