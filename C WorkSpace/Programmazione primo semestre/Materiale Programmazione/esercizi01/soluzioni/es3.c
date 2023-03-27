#include <stdio.h>

#define LIMITEMAX	300
#define LIMITMIN	100
#define	SCONTOMAX	0.1
#define SCONTOMIN	0.05

int main()
{
	float spesa;
	
	scanf("%f",&spesa);
	if (spesa >= LIMITEMAX) {
		spesa = (1-SCONTOMAX)*spesa;
	} else if (spesa >= LIMITMIN) {
		spesa = (1 - SCONTOMIN)*spesa;
	}
	
	printf("spesa = %f", spesa);

    return 0;
}
