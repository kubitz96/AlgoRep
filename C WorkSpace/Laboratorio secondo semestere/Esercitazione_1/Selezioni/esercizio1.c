/*fare un programa che stampi se un numero dato in input è pari o dispari (se è dispari stampare
DISPARI, se è pari stampare PARI)*/

#include<stdio.h>

int main()
{
	int x;

	printf("Inserire numero intero\n");
	scanf("%d", &x);

	if(x % 2 == 0) printf("PARI\n");
	else printf("DISPARI\n");

	return 0;
}