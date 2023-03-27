#include <stdio.h>

int main(void)
{
float base,altezza,perimetro,area;

printf("Inserisci base e altezza di un rettangolo per trovare area e perimetro\n");
printf("Inserisci base -->");
scanf("%f", &base);
printf("Inserisci altezza -->");
scanf("%f", &altezza);

area=base*altezza;
perimetro=(base+altezza)*2;

printf("Area=%f\nPerimetro=%f\n", area, perimetro);

return 0;
}
