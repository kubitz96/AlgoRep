//calcolo media di n valori inseriti da tastiera ma solo dei pari (con n inserito da input)

#include<stdio.h>

int main()
{
	int n;
	int x;
	int somma = 0;
	int cnt = 0;

	printf("Inserire quanti n valori utilizzare\n");
	scanf("%d", &n);

	printf("Inserire valori\n");

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		if(x % 2 == 0)
		{
			somma += x;
			++cnt;
		}
	}

	float media = somma/cnt;

	printf("La media dei pari inseriti e' %.2f\n", media);

	return 0;
}