// wap to print numbers between 0 and 10 , but skip the value 5 while displaying the output.

#include <stdio.h>

int main() {    
    int i;
    for (i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        printf("%d ", i);
    }
    return 0;   
}
