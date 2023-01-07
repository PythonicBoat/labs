/*
WAP to replace first letter of every word of the contents of a file with a capital letter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[SIZE];
    while (fgets(buffer, SIZE, fp) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (i == 0 || isspace(buffer[i - 1])) {
                buffer[i] = toupper(buffer[i]);
            }
        }
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}
