// wap to create a 2d array using strings

#include <stdio.h>
#include <string.h>

void main() {
    char str[3][20];
    for (int i = 0; i < 3; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s[^\n]", str[i]);
        //scanf("%s", str[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("String %d is %s", i + 1, str[i]);
    }
}
