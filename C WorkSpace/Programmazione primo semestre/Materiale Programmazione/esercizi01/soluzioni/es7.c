#include <stdio.h>

#define	TASSO_SCONTO_PENSIONATI		0.1
#define TASSO_SCONTO_STUDENTI		0.15
#define	TASSO_SCONTO_DISOCCUPATI	0.25
#define	STUDENTE					'S'
#define PENSIONATO					'P'
#define	DISOCCUPATO					'D'
#define ALTRO						'A'

void clearBuffer(void)
{
	char c;
	
	while( (c = getchar()) != '\n' && c != EOF); 
}

int main()
{
	float costo, tasso_di_sconto;
	char categoria;
	
	printf("Costo iniziale del biglietto --> ");
	scanf("%f",&costo);
	clearBuffer();
	printf("Categoria di sconto (%c %c %c %c): ", STUDENTE, PENSIONATO, DISOCCUPATO, ALTRO);
	scanf("%c", &categoria);
	
	switch(categoria) {
		case STUDENTE: tasso_di_sconto = TASSO_SCONTO_STUDENTI;
					   break;
		case PENSIONATO: tasso_di_sconto = TASSO_SCONTO_PENSIONATI;
						  break;
		case DISOCCUPATO: tasso_di_sconto = TASSO_SCONTO_DISOCCUPATI;
						  break;
		default: tasso_di_sconto = 0.0;
	}
	costo = costo - costo*tasso_di_sconto;
	
	printf("Costo biglietto = %.2f\n", costo);

    return 0;
}
