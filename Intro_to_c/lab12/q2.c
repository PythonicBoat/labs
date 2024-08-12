// wap to use the string manipulation functions to strcmp() strcpy() strcat() using the string

#include <stdio.h>
#include <string.h>

void main() {
    char s1[20], s2[20];
    printf("Enter the first string: ");
    scanf("%s[^\n]", s1);
    printf("Enter the second string: ");
    scanf("%s[^\n]", s2);
    int choice;
    printf("Enter choice:");
    scanf("%d", &choice);

    if (choice == 1) {
        // use strcmp() function
        if (strcmp(s1, s2) == 0) {
            printf("The strings are equal");
        } else {
            printf("The strings are not equal");
        }
    } else if (choice == 2) {
        // use strcpy() function
        strcpy(s1, s2);
        printf("The first string is now %s", s1);
    } else if (choice == 3) {
        // use strcat() function
        strcat(s1, s2);
        printf("The first string is now %s", s1);
    } else if (choice == 4) {
        printf("%s %s", s1, s2);
    } else {
        printf("Invalid Choice!");
    }
}
