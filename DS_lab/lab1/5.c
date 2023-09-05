// In addition to 1.4, perform the multiplication of two complex number using function (call by address).

// Sample Input/Output:
// Enter complex number 1: 2  3
// Enter complex number 2: 5  2
// Multiplication=4+19i

#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

void multiplyComplex(Complex *num1, Complex *num2, Complex *result) {
    result->real = num1->real * num2->real - num1->imag * num2->imag;
    result->imag = num1->real * num2->imag + num1->imag * num2->real;
}

int main() {
    Complex num1, num2, result;
    printf("Enter the first complex number (a + bi): ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter the second complex number (a + bi): ");
    scanf("%f %f", &num2.real, &num2.imag);
    multiplyComplex(&num1, &num2, &result);
    printf("Multiplication=%.2f+%.2fi\n", result.real, result.imag);
    return 0;
}
