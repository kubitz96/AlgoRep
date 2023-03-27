//calcolo media di serie di valori inseriti da tastiera ma solo dei pari(serie terminante con 0)

#include<stdio.h>

int main()
{
	int n = 0;
	int x;
	int somma = 0;

	printf("Inserire valori interi per calcolare la media (0 per terminare)\n");
	scanf("%d", &x);

	while(x != 0)
	{
		if(x % 2 == 0)
		{
			++n;
			somma += x;
		}
			scanf("%d", &x);
	}

	float media = somma/n;

	if(somma == 0) printf("La media e' 0\n");
	else printf ("La media dei pari e' %.2f\n", media);

	return 0;
}