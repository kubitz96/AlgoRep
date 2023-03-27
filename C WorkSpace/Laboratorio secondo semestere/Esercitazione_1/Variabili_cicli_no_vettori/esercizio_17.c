//dati due input b e h, stampa di un rettangolo fatto di * di base b e altezza h

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
			printf("*");
		}
		printf("\n");
	}

	return 0;
}