#include <stdio.h>

int main()
{
    char str[100];
    char *ptr, temp, temp1;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    ptr = str;
    printf("Enter the character you want to replace: ");
    scanf(" %c", &temp);
    printf("Enter the character you want to replace with: ");
    scanf(" %c", &temp1);
    while (*ptr != '\0')
    {
        if (*ptr == temp)
            *ptr = temp1;
        ptr++;
    }
    printf("The new string is: %s", str);
    return 0;
}
