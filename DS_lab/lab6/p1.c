// Write a menu driven program to create a stack using array and perform the following operation using function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

// Main Menu
// 1. Push
// 2. Pop
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
 
// Enter option: 1
// Enter element to be pushed into the stack: 22
// Enter option: 1
// Enter element to be pushed into the stack: 33
// Enter option: 1
// Enter element to be pushed into the stack: 44
// Enter option: 1
// Enter element to be pushed into the stack: 88
// Enter option: 1
// Enter element to be pushed into the stack: 66
// Enter option: 5
// Stack: 66  88  44  33  22
// Enter option: 2
// 66 deleted from Stack
// Enter option: 3
// Stack empty: False

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

void isEmpty(Stack *s, int top) {
    if (top=-1) {
        printf("Stack is Empty!");
    };
}

void isFull(Stack *s, int top) {
    if (top=99) {
        printf("Stack is Full!");
    };
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
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int value;
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                isEmpty(&s, s.top);
                break;
            case 4:
                isFull(&s, s.top);
                break;
            case 5:
                traverse(&s);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
}