// Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations
// Sample Input/Output
// Polynomial-1:
// Enter the Maximum power of x: 2
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1: 3

// Enter the coefficient of degree 0:2
// Polynomial-2:
// Enter the Maximum power of x: 3
// Enter the coefficient of degree 3: 5
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1:6
// Enter the coefficient of degree 0:10

// Sum: 5x^3+8x^2+9x^1+12x^0.

#include <stdio.h>

struct poly {
  int coeff;
  int expo;
};

void add_polynomials(struct poly *p1, struct poly *p2, struct poly *p3, int n1, int n2) {
  int i, j, k, n3;

  for (i = 0, j = 0, k = 0; i < n1 && j < n2;) {
    if (p1[i].expo == p2[j].expo) {
      p3[k].coeff = p1[i].coeff + p2[j].coeff;
      p3[k].expo = p1[i].expo;
      i++;j++;k++;
    } else if (p1[i].expo > p2[j].expo) {
      p3[k].coeff = p1[i].coeff;
      p3[k].expo = p1[i].expo;
      i++;k++;
    } else {
      p3[k].coeff = p2[j].coeff;
      p3[k].expo = p2[j].expo;
      j++;k++;
    }
  }

  for (; i < n1; i++, k++) {
    p3[k].coeff = p1[i].coeff;
    p3[k].expo = p1[i].expo;
  }

  for (; j < n2; j++, k++) {
    p3[k].coeff = p2[j].coeff;
    p3[k].expo = p2[j].expo;
  }

  n3 = k;
}

int main() {
  struct poly p1[10], p2[10], p3[20];
  int n1, n2, n3, i;

  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n1);

  printf("Enter the coefficients and exponents of the first polynomial: ");
  for (i = 0; i < n1; i++) {
    scanf("%d %d", &p1[i].coeff, &p1[i].expo);
  }

  printf("Enter the number of terms in the second polynomial: ");
  scanf("%d", &n2);

  printf("Enter the coefficients and exponents of the second polynomial: ");
  for (i = 0; i < n2; i++) {
    scanf("%d %d", &p2[i].coeff, &p2[i].expo);
  }

  add_polynomials(p1, p2, p3, n1, n2);

  printf("The sum of the polynomials is: ");
  for (i = 0; i < n3; i++) {
    printf("%d x^%d + ", p3[i].coeff, p3[i].expo);
  }

  printf("\b\b.\n");

  return 0;
}
