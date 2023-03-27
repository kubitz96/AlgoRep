/*dati due input b e h, stampa di un rettangolo di * di base b e altezza h avente sulla diagonale
principale il carattere #*/

#include<stdio.h>

int main()
{
	int b, h;

	printf("Inserire b e h rettangolo\n");
	scanf("%d%d", &b, &h);

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if(i == j) printf("#");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}