/*fare un programma che calcoli e stampi il risultato scambio del contenuto di due variabili,
stamparle prima e dopo lo scambio (ossia, date due variabili a e b, “spostare” in a il contenuto
della variabile b ed in b il contenuto della variabile a)*/

#include<stdio.h>

int main()
{
	int a = 5;
	int b = 3;
	int tmp;

	printf("valori a e b prima dello scambio: a = %d , b = %d\n", a, b);

	tmp = a;
	a = b;
	b = tmp;

	printf("valori a e b dopo lo scambio: a = %d , b = %d\n", a, b);

	return 0;
}