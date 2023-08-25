// wap to create, initialise, assign and access a pointer variable

#include <stdio.h>

int main() {
	char ch;
	char *pch;
	ch = 'A';
	pch = &ch;
	
	printf("Value of ch : %c\n", ch);
	printf("Address of cg : %p\n", &ch);
	
	printf("Value of ch : %c\n", *pch);
	printf("Address of ch : %p", pch);
	
	return 0;
}

