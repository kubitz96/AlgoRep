/*dati da tastiera due valori a e b, sommare tutti i numeri pari compresi, eventuali estremi
inclusi, tra a e b (es. se l’utente immette 2 e 7, il risultato dovrà essere 2 + 4 + 6 = 12)*/

#include<stdio.h>

int main()
{
	int somma = 0;
	int a, b, tmp;

	printf("Inserire numeri a e b\n");
	scanf("%d%d", &a, &b);

	if(b < a)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = a; i <= b; ++i)
	{
		if(i % 2 == 0) somma += i;
	}

	printf("La somma dei pari e' %d\n",somma);

	return 0;
}