/*
WAP to copy the contents of two files named as source1.txt and source2.txt into a third file dest.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s source1.txt source2.txt dest.txt\n", argv[0]);
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
    FILE *fp3 = fopen(argv[3], "w");
    if (fp3 == NULL) {
        printf("Error opening file %s!\n", argv[3]);
        return 1;
    }
    char ch;
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);
    }
    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);

    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
