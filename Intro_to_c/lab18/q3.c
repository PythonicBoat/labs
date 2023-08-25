/*
WAP to compare contents of two files and display appropriate message
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s file1.txt file2.txt\n", argv[0]);
        return 1;
    }
    FILE *fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("Error opening file %s!\n", argv[1]);
        return 1;
    }
    FILE *fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        printf("Error opening file %s!\n", argv[2]);
        return 1;
    }
    char ch1, ch2;
    int flag = 0;
    while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) {
        if (ch1 != ch2) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("The files are not identical!\n");
    } else {
        printf("The files are identical!\n");
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}