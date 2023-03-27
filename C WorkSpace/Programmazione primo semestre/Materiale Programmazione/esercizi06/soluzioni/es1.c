#include <stdio.h>
#include <stdlib.h>


int pow2(int n)
{
	int potenza = 1;
	int i;
	
	for (i=1; i<=n; i++) {
		potenza = 2*potenza;
	}
	
	return potenza;
}


int main()
{
	int N;
	int bit;
	int n = 0;
	int i;
	
	
	printf("Inserisci il numero di bit ");
	scanf("%d", &N);
	
	if (N<=0) {
		printf("Hai inserito u numero negativo o nullo\n");
		exit(-1);
	}
	
	for (i=N-1; i>=0; i--) {
		bit = getchar();
		if (bit=='1') n = n + pow2(i);
	}
	
	printf("Valore decimale : %d\n", n);
}
