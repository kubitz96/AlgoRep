#include <stdio.h>
#define LOWER 100
#define UPPER 300
#define SCMIN 0.05
#define SCMAX 0.1

int main(void)
{
float spesa;

scanf("%f",&spesa);
	if(spesa<=UPPER) {
		spesa= spesa*(1-SCMAX);}
	if(spesa<=LOWER) {
		spesa= spesa*(1-SCMIN);}

		printf("spesa = %4.2f euro\n", spesa);

return 0;
	}


	
