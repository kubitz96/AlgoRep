#include <stdio.h>

#define COSTO_MINIMO	100.00
#define COSTO_ORA		 40.00

int main()
{
	int Nore;
	float costo_materiale, costo;
	
	printf("Inserisci il numero di ore di lavoro -->");
	scanf("%d",&Nore);
	printf("Inserisci il costo del materiale --> ");
	scanf("%f",&costo_materiale);
	
	costo = Nore*COSTO_ORA;
	if (costo <= COSTO_MINIMO) {
		costo = COSTO_MINIMO;
	} 
	printf("Costo totale %.2f\n", costo + costo_materiale);

    return 0;
}
