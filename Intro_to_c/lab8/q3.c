// wap to find out the sum of the following series 1+11+111

#include <stdio.h>

void main() {
    int n, i;
    long sum=0;
    long int t=1;
    printf("Input the number of terms : \n");
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        printf("%ld ", t);
        if (i<n) {
            printf("+ ");
        }
        sum += t;
        t = (t*10)+1;
    }
    printf("The sum is %ld\n", sum);
}
