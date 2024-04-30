// Write a C program to design a Circular Doubly Linked List 
// and perform Insertion at end, Insertion at Beginning, Deletion at 
// Begin, Deletion at End, Insertion at Index, Deletion at Index, 
// Deletion of entire List, and Display Circular Doubly Linked List 
// operation.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteAtBegin(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        *head = temp->next;
        free(temp);
    }
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) return;
    Node* temp = (*head)->prev;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
        free(temp);
    }
}

void insertAtIndex(Node** head, int index, int data) {
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == *head) return; 
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtIndex(Node** head, int index) {
    if (*head == NULL || index < 0) return;
    Node* temp = *head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
        if (temp == *head) return; 
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp == *head) *head = temp->next;
    free(temp);
}

void deleteList(Node** head) {
    if (*head == NULL) return;
    Node* current = *head;
    Node* nextNode = NULL;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);
    *head = NULL;
}

void displayList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 0);
    insertAtIndex(&head, 1, 5);
    displayList(head);
    deleteAtBegin(&head);
    deleteAtEnd(&head);
    deleteAtIndex(&head, 0);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    displayList(head);
    deleteList(&head);
    return 0;
}
