// WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>

#define MAX_TERMS 101

typedef struct {
    int row;
    int col;
    int value;
} element;

void readMatrix(element a[]);
void printMatrix(element a[]);
void add(element a[], element b[], element c[]);

int main() {
    element a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    readMatrix(a);
    readMatrix(b);
    add(a, b, c);
    printf("\nMatrix A:\n");
    printMatrix(a);
    printf("\nMatrix B:\n");
    printMatrix(b);
    printf("\nMatrix C = A + B:\n");
    printMatrix(c);
    return 0;
}

void readMatrix(element a[]) {
    int numRows, numCols, numTerms;
    printf("Enter the number of rows, columns, and non-zero terms: ");
    scanf("%d%d%d", &numRows, &numCols, &numTerms);
    a[0].row = numRows;
    a[0].col = numCols;
    a[0].value = numTerms;
    for (int i = 1; i <= numTerms; i++) {
        printf("Enter row, column, and value of term %d: ", i);
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].value);
    }
}

void printMatrix(element a[]) {
    int numRows = a[0].row;
    int numCols = a[0].col;
    int numTerms = a[0].value;
    int index = 1;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == a[index].row && j == a[index].col) {
                printf("%d ", a[index].value);
                index++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void add(element a[], element b[], element c[]) {
    int numRows = a[0].row;
    int numCols = a[0].col;
    int numTermsA = a[0].value;
    int numTermsB = b[0].value;
    int indexA = 1;
    int indexB = 1;
    int indexC = 1;
    c[0].row = numRows;
    c[0].col = numCols;
    while (indexA <= numTermsA && indexB <= numTermsB) {
        if (a[indexA].row < b[indexB].row) {
            c[indexC].row = a[indexA].row;
            c[indexC].col = a[indexA].col;
            c[indexC].value = a[indexA].value;
            indexA++;
            indexC++;
        } else if (a[indexA].row > b[indexB].row) {
            c[indexC].row = b[indexB].row;
            c[indexC].col = b[indexB].col;
            c[indexC].value = b[indexB].value;
            indexB++;
            indexC++;
        } else {
            if (a[indexA].col < b[indexB].col) {
                c[indexC].row = a[indexA].row;
                c[indexC].col = a[indexA].col;
                c[indexC].value = a[indexA].value;
                indexA++;
                indexC++;
            } else if (a[indexA].col > b[indexB].col) {
                c[indexC].row = b[indexB].row;
                c[indexC].col = b[indexB].col;
                c[indexC].value = b[indexB].value;
                indexB++;
                indexC++;
            } else {
                c[indexC].row = a[indexA].row;
                c[indexC].col = a[indexA].col;
                c[indexC].value = a[indexA].value + b[indexB].value;
                indexA++;
                indexB++;
                indexC++;
            }
        }
    }
    while (indexA <= numTermsA) {
        c[indexC].row = a[indexA].row;
        c[indexC].col = a[indexA].col;
        c[indexC].value = a[indexA].value;
        indexA++;
        indexC++;
    }
    while (indexB <= numTermsB) {
        c[indexC].row = b[indexB].row;
        c[indexC].col = b[indexB].col;
        c[indexC].value = b[indexB].value;
        indexB++;
        indexC++;
    }
    c[0].value = indexC - 1;
}