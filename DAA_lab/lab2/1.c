// WAP in c to convert the first n decimal numbers of a disc file to binary using recursion. Store the binary value in seperate file.

#include <stdio.h>
#include <stdlib.h>

void decToBinary(int n, FILE *fp)
{
    if (n == 0)
        return;
    decToBinary(n / 2, fp);
    fprintf(fp, "%d", n % 2);
}

int main()
{
    FILE *fp1, *fp2;
    int n, num;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    if (fp1 == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    printf("Enter the number of decimal numbers to convert to binary: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp1, "%d", &num);
        decToBinary(num, fp2);
        fprintf(fp2, "\n");
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
