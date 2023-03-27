//verificare se una stringa è palindroma

#include<stdio.h>

#define SIZE 5

int main()
{
	char stringa[SIZE] = "otto";

	int pal = 1;

	for (int i = 0, n = SIZE-2; i < SIZE/2 && pal == 1; ++i, --n)
	{
		if(stringa[i] != stringa[n]) pal = 0;
	}

	if(pal) printf("Palindroma\n");
	else printf("No\n");

	return 0;
}