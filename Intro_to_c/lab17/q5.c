// wap to display the size of a structure and union of two nmes having similar data members

#include <stdio.h>

struct abc
{
    char a;
    int b;
    double c;
};

union xyz
{
    char a;
    int b;
    double c;
};

void main()
{
    struct abc x;
    union xyz y;
    printf("Size of structure: %lu\n", sizeof(x));
    printf("Size of union: %lu\n", sizeof(y));
}
