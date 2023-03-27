#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;
	int riga, colonna;
	int cifra;
	
	printf("Inserisci un intero positivo ");
	scanf("%d", &numero);
	
	cifra = 1;
	
	for (riga=0; riga<numero; riga++) {
		for (colonna=0; colonna<=riga; colonna++) {
			printf("%3d", cifra);
			cifra++;
		}
		printf("\n");
	}
}

8
10101010
170
