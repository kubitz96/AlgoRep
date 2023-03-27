#include <stdio.h>

int main ()
{
	double x = 7e+33;
	double y = 0.001;
	
	if (x < x + y) printf("x < x + y\n");
	if (x > x + y) printf("x > x + y\n");
	if (x == x + y) printf("x = x + y\n");
}
