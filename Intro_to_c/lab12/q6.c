// wap to find whether a string is palindrome or not

#include <stdio.h>

void main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    int i = 0;
    while (i < len / 2) {
        if (str[i] != str[len - i - 1]) {
            printf("Not a palindrome");
            return;
        }
        i++;
    }
    printf("Palindrome");
}