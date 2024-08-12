// wap to count the number of digits using recursion

#include <stdio.h>

int countDigits(int number) {
	int count = 0;
	if (number>0) {
		count++;
		countDigits(num(123));
	}
	else {
		return count;
	}
}

void main() {
	int number;
	int count=0;
	
	printf("Enter a positive number : ");
	scanf("%d", &number);
	
	count = countDigits(number);
	
	printf("Total digits in the given number is %d\n", count);
}
