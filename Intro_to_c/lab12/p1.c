#include <stdio.h>

void add() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Sum is %d", a + b);
}

void sub() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Difference is %d", a - b);
}

void mul() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Product is %d", a * b);
}

void div() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Quotient is %d", a / b);
}

void main() {
    int choice;
    printf("1. Add\n 2. Sub\n3. Mul\n 4. Div");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            div();
            break;
        default:
            printf("Invalid choice");
    }
}
