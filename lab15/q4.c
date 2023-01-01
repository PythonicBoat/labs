#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    char *s;

    printf("Enter a string: ");
    scanf("%s", string);

    s = string;

    printf("The reversed string: ");
    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", *(s + i));
    }
    printf("\n");

    return 0;
}
