#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int top;
    int data[MAX];
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    s->top--;
}

void isEmpty(Stack *s) {
    if (s->top == -1) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack is not Empty!\n");
    }
}

void traverse(Stack *s) {
    int i;
    for (i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    s.top = -1;
    int choice;
    do {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                int value;
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                isEmpty(&s);
                break;
            case 4:
                traverse(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
}