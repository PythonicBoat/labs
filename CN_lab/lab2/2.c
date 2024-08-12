// Big Little Endian

#include <stdio.h>

int main() {
    unsigned int x = 0x76513210;
    char *c = (char *) &x;
    printf("*c is : 0x%x\n", *c);

    if (*c == 0x10) {
        printf("The system is little endian.\n");
    } else {
        printf("The system is big endian.\n");
    }
    return 0;
}