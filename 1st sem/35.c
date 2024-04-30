#include<stdio.h>
int main(){
    char ch;
    FILE *s1;
    s1=fopen("student.txt","w+");
    fprintf(s1,"Name:- Sougata Pal,Roll:-702");
    while(fscanf(s1,"%c",&ch)!=EOF){
        printf("%c",ch);
    }
    fclose(s1);
    return 0;
}