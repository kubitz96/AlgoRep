#include <stdio.h>


int main()
{
	float a, b;
	float buff;
	
	a = 5.0;
	b = 7.0;
	
	printf("a = %f, b = %f\n", a, b);
	buff = a;
	a = b;
	b = buff;
	
	printf("a = %f, b = %f\n", a, b);
}

