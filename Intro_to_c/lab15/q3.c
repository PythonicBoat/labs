// wap to find the total number of vowels in a string

#include <stdio.h>
#include <math.h>
#include <string.h>

void Solve()
{
	unsigned short count = 0, vowels = 0;
    char str[100], c;
    printf("Enter a string in which you want to find number of vowels: ");
    scanf("%[^\n]", str);
    while(str[count] != '\0') {
    	c = str[count];
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
        vowels++;
        printf("%c", c);
     }
     count++;
   }
   printf("\n");
   printf("Number of vowels in the given strings : %hu \n", vowels);
}

void main()
{
    Solve();
}
