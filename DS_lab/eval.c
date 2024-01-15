// Convert a user given infix expression to postfix expression and evaluate it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int isOperator(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}

int precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void convertToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;
    stack[++top] = '#';

    for(i = 0; i<strlen(infix); i++) {
        symbol = infix[i];

        if(isOperator(symbol) == 0) {
            postfix[j] = symbol;
            j++;
        } else {
            while(precedence(stack[top]) >= precedence(symbol)) {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }
    }

    while(stack[top] != '#') {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    char ch;
    int i = 0, op1, op2;
    while((ch = postfix[i++]) != '\0') {
        if(isdigit(ch)) {
            push(ch-'0');
        } else {
            op2 = pop();
            op1 = pop();
            switch(ch) {
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
            }
        }
    }
    return stack[top];
}

int main() {
    char infix[SIZE], postfix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);
    convertToPostfix(infix,postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    printf("Evaluated Expression: %d", evaluatePostfix(postfix));
    return 0;
}

void convertToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char symbol;
    stack[++top] = '#';
9
    for(i = strlen(infix)-1; i>=0; i--) {
        symbol = infix[i];

        if(isOperator(symbol) == 0) {
            prefix[j] = symbol;
            j++;
        } else {
            while(precedence(stack[top]) >= precedence(symbol)) {
                prefix[j] = pop();
                j++;
            }
            push(symbol);
        }
    }

    while(stack[top] != '#') {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';
}

int evaluatePrefix(char* prefix) {
    char ch;
    int i = strlen(prefix)-1, op1, op2;
    while(i>=0) {
        ch = prefix[i--];
        if(isdigit(ch)) {
            push(ch-'0');
        } else {
            op1 = pop();
            op2 = pop();
            switch(ch) {
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
            }
        }
    }
    return stack[top];
}

int main() {
    char infix[SIZE], prefix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);
    convertToPrefix(infix,prefix);
    printf("Prefix Expression: ");
    puts(prefix);
    printf("Evaluated Expression: %d", evaluatePrefix(prefix));
    return 0;
}