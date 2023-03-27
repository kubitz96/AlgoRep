#include <stdio.h>

#define	SCONTOPENSIONATI  0.10
#define SCONTOSTUDENTI	  0.15
#define SCONTODISOCCUPATI 0.25
#define PENSIONATI 		   'P'
#define STUDENTI		   'S'
#define DISOCCUPATI		   'D'
#define ALTRO 			   'A'

void clear (void)
{    
  while ( getchar() != '\n' );
}

int main(void)
{
char categoria;
float prezzobiglietto,sconto;

printf("prezzo iniziale biglietto-->");
scanf("%f",&prezzobiglietto);
clear();
printf("Categorie di sconto %c %c %c %c:", PENSIONATI, STUDENTI, DISOCCUPATI, ALTRO);
scanf("%c",&categoria);

switch(categoria){
case PENSIONATI: sconto=SCONTOPENSIONATI;
break;
case STUDENTI: sconto=SCONTOSTUDENTI;
break;
case DISOCCUPATI: sconto=SCONTODISOCCUPATI;
break;
default: sconto=0;
}

printf("Costo biglietto %.2f euro\n", prezzobiglietto*(1-sconto));

return 0;
}
