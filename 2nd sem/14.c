// Write a C program to implement Deque using array. Perform
// the operations add to front, add to rear, delete from front, delete
// from rear, and display.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

int isFull(Deque *dq)
{
    return (dq->size == MAX);
}

int isEmpty(Deque *dq)
{
    return (dq->size == 0);
}

void addFront(Deque *dq, int key)
{
    if (isFull(dq))
    {
        printf("Overflow\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = key;
    dq->size++;
}

void addRear(Deque *dq, int key)
{
    if (isFull(dq))
    {
        printf("Overflow\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = key;
    dq->size++;
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Underflow\n");
        return;
    }
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        if (dq->front == MAX - 1)
        {
            dq->front = 0;
        }
        else
        {
            dq->front++;
        }
    }
    dq->size--;
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Underflow\n");
        return;
    }
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
    dq->size--;
}

void displayDeque(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque dq;
    initDeque(&dq);

    addFront(&dq, 1);
    addRear(&dq, 2);
    displayDeque(&dq);
    deleteFront(&dq);
    addFront(&dq, 3);
    displayDeque(&dq);
    deleteRear(&dq);
    displayDeque(&dq);

    return 0;
}
