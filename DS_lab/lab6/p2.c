// 6.2 Write a program to convert infix expression to postfix operation using stack.

// Sample Input/Output
// Enter infix expression: (a+b)/c*d-e^f
// Postfix: ab+c/d*ef^-

#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();

int main()
{
    char infix[MAX], postfix[MAX], ch, elem;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (ch == ')')
            while ((elem = pop()) != '(')
                postfix[k++] = elem;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (top != -1 && stack[top] != '(' && ((ch == '^' && stack[top] == '^') || (ch == '*' && stack[top] == '/') || (ch == '/' && stack[top] == '*') || (ch == '+' && stack[top] == '-') || (ch == '-' && stack[top] == '+')))
                postfix[k++] = pop();
            push(ch);
        }
        else
            postfix[k++] = ch;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}

void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}
