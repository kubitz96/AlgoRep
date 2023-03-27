#include <stdio.h>

#define BIG	2000000000

int main()
{
	unsigned int a, b, c;
	
	b = c = BIG;
	
	a = b + c;
	
	printf("a = %d\n", a);
	
	return 0;
}
