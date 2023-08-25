// wap to print prime number between 1 and 20, using do while loop

#include <stdio.h>

int main()
{
    int i = 1, j, flag;
    do
    {
        flag = 0;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d ", i);
        }
        i++;
    } while (i <= 20);
    return 0;
}
