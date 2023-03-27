//calcolare la lunghezza di una stringa senza utilizzare la funzione string length (strlen)

#define MAXLEN 100

#include<stdio.h>

int main()
{
	char c = '0';
	int len = 0;

	printf("Inserire Stringa\n");

	c = getchar();

	while(c != '\n')
	{
		++ len;
		c = getchar();
	}

	printf("caratteri letti %d\n", len);

	return 0;
}