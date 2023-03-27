#include <stdio.h>
#define PAGAORA  40.00
#define COSTOMIN 100.00

int main(void)
{
int ore;
float materiale,prezzo;

printf("inserire le ore di lavoro e il costo dei materiali per il prezzo totale\n");
scanf("%d %f",&ore,&materiale);

prezzo= PAGAORA*ore;
if (prezzo+materiale<=COSTOMIN) {prezzo=COSTOMIN;}
else(prezzo=prezzo+materiale);

printf("prezzo %.2f euro\n",prezzo);

return 0;
}
