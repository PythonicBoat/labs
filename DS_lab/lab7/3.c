#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void push(Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

void towerOfHanoi(int n, Stack *source, Stack *auxiliary, Stack *destination) {
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }
    if (n % 2 == 0) {
        while (destination->top != n - 1) {
            int temp = pop(source);
            push(auxiliary, temp);
            printf("Move disk %d from %c to %c\n", temp, 'A', 'B');
            temp = pop(source);
            push(destination, temp);
            printf("Move disk %d from %c to %c\n", temp, 'A', 'C');
            temp = pop(auxiliary);
            push(destination, temp);
            printf("Move disk %d from %c to %c\n", temp, 'B', 'C');
        }
    } else {
        while (destination->top != n - 1) {
            int temp = pop(source);
            push(destination, temp);
            printf("Move disk %d from %c to %c\n", temp, 'A', 'C');
            temp = pop(source);
            push(auxiliary, temp);
            printf("Move disk %d from %c to %c\n", temp, 'A', 'B');
            temp = pop(destination);
            push(auxiliary, temp);
            printf("Move disk %d from %c to %c\n", temp, 'C', 'B');
        }
    }
}

int main() {
    int n;
    printf("Enter number of disks n: ");
    scanf("%d", &n);
    Stack source = {-1};
    Stack auxiliary = {-1};
    Stack destination = {-1};
    towerOfHanoi(n, &source, &auxiliary, &destination);
    return 0;
}