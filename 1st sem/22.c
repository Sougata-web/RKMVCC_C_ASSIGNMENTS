// simple interest calculation

#include<stdio.h>
float interest(int p, int r, int t){
    return (p*r*t)/100;
}
int main(){
    int pr,rt,tm;
    printf("Enter your principle amount, rate, time: \n");
    scanf("%d%d%d", &pr,&rt,&tm);
    printf("The interest is: %f", interest(pr,rt,tm));
    return 0;
}