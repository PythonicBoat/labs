#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int size)
{
    char temp;
    if (size > 0)
    {
        temp = str[0];
        str[0] = str[size-1];
        str[size-1] = temp;
        reverse_string(&str[1], size-2);
    }
}

int main()
{
    char a[50];
    printf("Enter string : ");
    scanf("%s", a);
    reverse_string(a, strlen(a));
    printf("%s\n", a);
    return 0;
}
