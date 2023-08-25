// wap to reverse a string

#include <stdio.h>
#include <string.h>

void main() {
	char str[50], temp;
	int i=0, j=0;
	printf("Enter a string a reversed : ");
	scanf("%s", str);
	j = strlen(str) - 1;
	while (i<j) {
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
	printf("The reversed of the string : %s", str);
}
