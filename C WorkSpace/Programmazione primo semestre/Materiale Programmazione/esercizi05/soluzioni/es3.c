#include <stdio.h>
#include <stdlib.h>

int max3(int a, int b, int c)
{
	int m;
	
	if (a >= b && a >= c) {
		m = a;
	} else if (b>=a && b>=c) {
		m = b;
	} else {
		m = c;
	}
	
	
	return m;
}

