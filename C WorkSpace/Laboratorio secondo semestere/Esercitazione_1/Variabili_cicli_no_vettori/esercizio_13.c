/*Acquisita l’altezza per N individui (con N inserito da tastiera), calcolare:
1) l’altezza media,
2) il numero di persone più alte di m. 1,80,
3) il numero di persone più basse di m. 1,65.*/

#include<stdio.h>

int main()
{
	int N;
	float altezza;
	float somma = 0;
	int alte = 0;
	int basse = 0;

	printf("Inserire N individui\n");
	scanf("%d", &N);

	printf("Inserire altezza in metri di ogni individuo\n");

	for(int i = 0; i < N; ++i)
	{
		scanf("%f", &altezza);
		somma += altezza;

		if(altezza > 1.80) ++alte;
		if(altezza < 1.65) ++basse;
	}

	float media = somma/N;

	printf("Altezza media : %1.2f\n", media);
	printf("Persone piu' alte di 1,80 : %d\n", alte);
	printf("Persone piu' basse di 1,65 : %d\n", basse);

	return 0;
}