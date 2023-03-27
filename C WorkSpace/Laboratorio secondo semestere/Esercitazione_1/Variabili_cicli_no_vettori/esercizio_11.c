//calcolo media di n valori inseriti da tastiera (con n inserito da input)

#include<stdio.h>

int main()
{
	int n;
	int x;
	int somma = 0;

	printf("Inserire quanti n valori utilizzare\n");
	scanf("%d", &n);

	printf("Inserire valori\n");

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		somma += x;
	}

	float media = somma/n;

	printf("La media e' %.2f\n", media);

	return 0;
}