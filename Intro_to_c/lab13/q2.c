// wap to find out all the prime numbers between 1 to n, using a function isprime()

#include <stdio.h>

int isprime(int n);

int main()
{
	int n, i;
	printf("Enter a number: ");
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		if (isprime(i))
			printf("%d ", i);
	return 0;
}

int isprime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
