//  Write a C program to design a Circular Linked List and 
// perform Insertion at end, Insertion at Beginning, Deletion at 
// Begin, Deletion at End, Insertion at Index, Deletion at Index, 
// Deletion of entire List, and Display Circular Linked List 
// operation.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteAtBegin(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

void insertAtIndex(Node** head, int index, int data) {
    Node* newNode = createNode(data);
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp->next != *head && i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtIndex(Node** head, int index) {
    if (*head == NULL || index < 0) return;
    Node* temp = *head;
    if (index == 0) {
        deleteAtBegin(head);
        return;
    }
    Node* prev = NULL;
    for (int i = 0; temp->next != *head && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) return; 
    prev->next = temp->next;
    free(temp);
}

void deleteList(Node** head) {
    if (*head == NULL) return;
    Node* current = *head;
    Node* next = current->next;
    while (next != *head) {
        current = next;
        next = current->next;
        free(current);
    }
    free(*head);
    *head = NULL;
}

void displayList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
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
