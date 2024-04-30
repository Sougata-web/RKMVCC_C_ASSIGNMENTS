// Write a C program to design a Singly Linked List and 
// perform Insertion at end, Insertion at Beginning, Deletion at 
// Begin, Deletion at End, Insertion at Index, Deletion at Index, 
// Deletion of entire List and Display Linked List operation on it

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void insertAtIndex(Node** head, int index, int data) {
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index is out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtIndex(Node** head, int index) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (index == 0) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index is out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtIndex(&head, 1, 30);
    displayList(head);
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteAtIndex(&head, 0);
    displayList(head);
    deleteList(&head);

    return 0;
}
