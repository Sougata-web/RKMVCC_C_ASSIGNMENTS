#include <stdio.h> 
#include <string.h> 
typedef struct Book { 
    char title[100]; 
    char author[100]; 
    int year; 
}Book; 
int main()  
{ 
    Book books[10]; 
    for (int i = 0; i < 10; i++)  
    { 
        printf("Enter data for Book %d:\n", i + 1); 
        printf("Title: "); 
        fgets(books[i].title, sizeof(books[i].title), stdin); 
        printf("Author: "); 
        fgets(books[i].author, sizeof(books[i].author), stdin); 
        printf("Year: "); 
        scanf("%d", &books[i].year); 
        while (getchar() != '\n'); 
    } 
    printf("\nBook Information:\n"); 
    for (int i = 0; i < 10; i++)  
    { 
        printf("Book %d:\n", i + 1); 
        printf("Title: %s", books[i].title); 
        printf("Author: %s", books[i].author); 
        printf("Year: %d\n", books[i].year); 
        printf("\n"); 
    } 
    return 0; 
} 
