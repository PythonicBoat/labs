// Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front = front - 1;
    deque[front] = item;
    printf("Inserted %d at front\n", item);
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX-1)
        rear = 0;
    else
        rear = rear + 1;
    deque[rear] = item;
    printf("Inserted %d at rear\n", item);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element %d from front\n", deque[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == MAX-1)
        front = 0;
    else
        front = front + 1;
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element %d from rear\n", deque[rear]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear = rear - 1;
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Elements in deque are: ");
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    else {
        for (i = front; i < MAX; i++)
            printf("%d ", deque[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("1.Insert at the front end\n");
        printf("2.Insert at the rear end\n");
        printf("3.Delete from front end\n");
        printf("4.Delete from rear end\n");
        printf("5.Display all elements of deque\n");
        printf("6.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted at front end: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to be inserted at rear end: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting from program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}