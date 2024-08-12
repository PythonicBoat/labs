// // wap to reverse a string

// #include <stdio.h>
// #include <string.h>

// void main() {
//     char str[100];
//     printf("Enter a string: ");
//     scanf("%s", str);
//     int len = strlen(str);
//     for (int i = len - 1; i >= 0; i--) {
//         printf("%c", str[i]);
//     }
// }

// wap to reverse a string using for loop 

#include <stdio.h>
#include <strings.h>
#define revstr main

void revstr(char str[]) {

    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}
