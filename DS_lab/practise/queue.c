#include <stdio.h>
#define SIZE 5

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* q, int value) {
    if(q->rear == SIZE - 1)
        printf("Queue is Full\n");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

void dequeue(struct Queue* q) {
    if(q->front == -1)
        printf("Queue is Empty\n");
    else {
        printf("Removed -> %d\n", q->items[q->front]);
        q->front++;
        if(q->front > q->rear)
            q->front = q->rear = -1;
    }
}

void peek(struct Queue* q) {
    if(q->front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front Element -> %d\n", q->items[q->front]);
}

void display(struct Queue* q) {
    if(q->rear == -1)
        printf("Queue is Empty\n");
    else {
        int i;
        printf("Queue elements:\n");
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->items[i]);
        printf("\n");
    }
}

void empty(struct Queue* q) {
    if(q->front == -1)
        printf("Queue is Empty\n");
    else {
        int i;
        printf("Queue elements:\n");
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->items[i]);
        printf("\n");
    }
}

void full(struct Queue* q) {
    int value = SIZE;
    if(q->rear == SIZE - 1)
        printf("Queue is Full\n");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Empty\n6. Full\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: peek(&q);
                    break;
            case 4: display(&q);
                    break;
            case 5: empty(&q);
                    break;
            case 6: full(&q);
                    break;
            case 7: printf("Exit\n");
                    break;

            default: printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}