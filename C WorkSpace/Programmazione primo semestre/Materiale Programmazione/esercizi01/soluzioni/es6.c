#include <stdio.h>

#define	PERX	100.0

int main()
{
	float prezzo;
	int sconto;
	
	printf("prezzo --> ");
	scanf("%f",&prezzo);
	printf("sconto --> ");
	scanf("%d", &sconto);
	
	prezzo = prezzo - prezzo*sconto/PERX;
	
	printf("prezzo scontato = %.2f\n", prezzo);

    return 0;
}
