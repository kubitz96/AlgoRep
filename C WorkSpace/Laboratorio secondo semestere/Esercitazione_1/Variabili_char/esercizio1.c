/*dato un carattere da tastiera, determinare se è maiuscolo o minuscolo e convertirlo
nel rispettivo minuscolo/maiuscolo*/

#include<stdio.h>
#include<ctype.h>

int main()
{
	int c;

	printf("Inserire carattere\n");
	c = getchar();

	if(islower(c))
	{
		printf("La lettera e' minuscola\n");
		c = toupper(c);
	}

	else if(isupper(c))
	{
		printf("La lettera e' maiuscola\n");
		c = tolower(c);
	}

	printf("La lettera trasformata e' %c\n", c);

	return 0;
}