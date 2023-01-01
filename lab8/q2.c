// wap to find the cube of the number from 1 to 5 and display the output

#include <stdio.h>
#include <math.h>

int main()
{
    int i, cube;
    for (i = 1; i <= 5; i++)
    {
        cube = pow(i, 3);
        printf("%d\n", cube);
    }
    return 0;
}
