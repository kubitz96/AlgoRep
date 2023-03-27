#include <stdio.h>
#include <limits.h>

int main() 
{
	int n;
	int somma, sommaPari, sommaDispari;
	int min, max;
	int count = 0;
	
	somma = sommaPari = sommaDispari = 0;
	
	//min = INT_MAX;
	//max = INT_MIN;
	while ( scanf("%d", &n)  && n != 0) {
		if (count == 0) {
			min = max = n;
		}
		count++;
		if (count % 2 == 0) {
			sommaPari = sommaPari + n;
		}
		else {
			sommaDispari = sommaDispari + n;
		}
		
		
		min = (min > n) ? n : min;
		max = (max < n) ? n : max;
		
	}
	
	printf("valore minimo : %d\n", min);
	printf("valore massimo: %d\n", max);
	printf("somma pari	  : %d\n", sommaPari);
	printf("somma dispari : %d\n", sommaDispari);
	printf("somma totale  : %d\n", sommaDispari + sommaPari);
	
	return 0;
	
}
