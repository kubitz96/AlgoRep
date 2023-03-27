#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *r;
	double x;
	
	x = 5.765;
	
	r = &((int) x);
	
	printf("%d\n", *r);
}
