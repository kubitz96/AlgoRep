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

7
00111



int main()
{
	int N;
	int bit;
	int n;
	int i;
	
	
	printf("Inserisci il numero di bit ");
	scanf("%d", &N);
	
	printf("Inserisci il numero da convertire ");
	scanf("%d",&n);
	
	if (N<=0) {
		printf("Hai inserito u numero negativo o nullo\n");
		exit(-1);
	}
	
	if (pow2(N) < n ) {
		printf("Numero di bit insufficiente\n");
		exit(-2);
	}
	
	for (i=N-1; i>=0; i--) {
		if (pow2(i) <= n) {
			putchar('1');
			n = n - pow2(i);
		}
		else putchar('0');
	}
}
