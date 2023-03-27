#include <stdio.h>

int main(void)
{
float prezzo;
int sconto;

printf("prezzo-->");
scanf("%f",&prezzo);
printf("sconto-->");
scanf("%d",&sconto);

printf("costo %.2f euro\n", prezzo-(prezzo/100*sconto));
return 0;
}
