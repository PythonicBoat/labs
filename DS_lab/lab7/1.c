#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Function to check if the input expression has balanced parentheses
int areParenthesesBalanced(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    int i;
    for (i = 0; exp[i]; ++i) {
        if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            if (isEmpty(stack))
                return 0;
            pop(stack);
        }
    }
    return isEmpty(stack);
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    gets(exp);
    if (areParenthesesBalanced(exp))
        printf("Output: True\n");
    else
        printf("Output: False\n");
    return 0;
}
