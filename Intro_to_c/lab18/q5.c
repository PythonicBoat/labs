/*
WAP to print the content of a file in reverse order
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s file.txt\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s!\n", argv[1]);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char ch;
    for (int i = size - 1; i >= 0; i--) {
        fseek(fp, i, SEEK_SET);
        ch = fgetc(fp);
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}
