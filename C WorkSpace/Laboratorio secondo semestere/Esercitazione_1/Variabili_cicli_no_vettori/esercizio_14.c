//calcolo media di serie di valori inseriti da tastiera (serie terminante con 0)

#include<stdio.h>

int main()
{
	int n = 0;
	float x;
	float somma = 0;

	printf("Inserire valori per calcolare la media (0 per terminare)\n");
	scanf("%f", &x);

	while(x != 0)
	{
		++n;
		somma += x;
		scanf("%f", &x);
	}

	float media = somma/n;

	if(somma == 0) printf("La media e' 0\n");
	else printf ("La media e' %.2f\n", media);

	return 0;
}