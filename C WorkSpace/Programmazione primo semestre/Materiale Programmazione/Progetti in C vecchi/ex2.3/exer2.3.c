#include <stdio.h>

int main(void)
{
	int a, b;
	int buff;
	a=5;
	b=7;

		printf("a=%d b=%d\n", a, b);
	buff=a;
	a=b;
	b=buff;
		printf("a=%d b=%d\n", a, b);

	return 0;


	}
