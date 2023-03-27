#include <stdio.h>
#include <stdlib.h>

int mcm(int n1, int n2)
{
	int max, min;
	int m;
	
	if (n1 < n2) max = n2;
	else max = n1;
	min = (n1 < n2) ? n1 : n2;
	
	m = max;
	while ( m % min != 0 || m % max != 0) {
		m = m + max;
	}
	
	return m;
}


int main()
{
	int numero1, numero2;
	
	printf("Inserisci due numeri positivi ");
	scanf("%d%d", &numero1, &numero2);
	
	if (numero1 <= 0 || numero2 <=0) {
		printf("Errore. Hai inserito un valore negativo o nullo");
		exit(-1);
	}
	
	printf("Il mcm fra %d e %d: %d\n", numero1, numero2, mcm(numero1, numero2));
	
	return 0;
}
