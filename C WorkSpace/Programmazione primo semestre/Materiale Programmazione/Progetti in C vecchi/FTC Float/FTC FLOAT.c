#include <stdio.h>

int main(void)
{
float fahr, celsius;
int lower, upper, step;

lower=0;
upper=300;
step=20;
fahr=lower;

printf("Fahreneit   ");
printf ("|Celsius\n");

while (fahr<=upper)
{
celsius=(5.0/9.0)*(fahr-32);
printf("%5.0f         %6.2f\n", fahr, celsius);
fahr+=step;
}
return 0;
}
