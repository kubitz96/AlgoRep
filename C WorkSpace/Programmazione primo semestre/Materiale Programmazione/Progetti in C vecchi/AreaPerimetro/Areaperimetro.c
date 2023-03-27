#include <stdio.h>

int main(void)
{
int base, altezza;
int perimetro, area;

printf("scrivi la base e l'altezza di un triangolo\n");
printf("base-->");
scanf("%d",&base);
printf("altezza-->");
scanf("%d",&altezza);

area=base*altezza;
perimetro=2*(base+altezza);

printf("Area = %d\nPerimetro = %d\n", area, perimetro);

return 0;
}
