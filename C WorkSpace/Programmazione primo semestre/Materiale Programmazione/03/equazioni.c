#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	float a, b, c;
	float delta;
	float x1, x2;
	
	scanf("%f%f%f", &a, &b, &c);
	delta = b*b - 4*a*c;
	
	if (delta >= 0) {
		x1 = (-b - sqrt(delta))/(2*a);
		x2 = (-b + sqrt(delta))/(2*a);
		printf("Le soluzioni sono %f %f \n", x1, x2);
	}
	else {
		printf("Non ammette soluzioni reali\n");
	}
	
	return 1;
}
