// WAP in c to find GCD of two numbers using recursion. Read all pairs of numeber from a file and store the result in another file. The source file must contain atleast 20 pairs of numbers. The input and output files are taken as command line arguments. 

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int a, b, count = 0;
    while (fscanf(inputFile, "%d %d", &a, &b) == 2 && count < 20) {
        int result = gcd(a, b);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", a, b, result);
        count++;
    }

    if (count < 20) {
        printf("Input file does not contain at least 20 pairs of numbers.\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}