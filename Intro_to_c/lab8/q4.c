// wap to find out the numbers between 100 and 200 that are divisible by 9 
// and display the multiplied value by 9

#include <stdio.h>

void main() {
    int i;
    for (i=100; i<=200; i++) {
        if (i%9==0) {
            printf("%d ", i);
        }
    }
    printf("%d times 9 is %d\n", i, i*9);
}
