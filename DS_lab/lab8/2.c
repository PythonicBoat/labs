// Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int);
int dequeue();
void traverse();
int isEmpty();
int isFull();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. IsEmpty\n5. IsFull\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data != -1)
                printf("Dequeued element: %d\n", data);
            break;
        case 3:
            traverse();
            break;
        case 4:
            if (isEmpty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 5:
            if (isFull())
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return data;
}

void traverse()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
        printf("%d ", queue[i]);
    printf("%d\n", queue[i]);
}

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % MAX == front;
}