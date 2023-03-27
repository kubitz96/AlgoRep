#include <stdio.h>
#include <stdlib.h>

int mcd(int n1, int n2)
{
	int min;
	int divisore;
	
	min = (n1 < n2) ? n1 : n2;
	
	divisore = min;
	
	while ( n1 % divisore != 0  ||  n2 % divisore !=0) {
		divisore--;
	}
	
	
	return divisore;
}


int main()
{
	int numero1, numero2;
	
	printf("Inserisci due interi positivi ");
	scanf("%d%d",&numero1, &numero2);
	
	printf("Il mcd fra %d e %d: %d\n", numero1, numero2, mcd(numero1, numero2));
	
	return 0;
	
}
