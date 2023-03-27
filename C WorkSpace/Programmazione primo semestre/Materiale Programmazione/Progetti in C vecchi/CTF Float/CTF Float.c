#include <stdio.h>

int main()
{
float celsius, fahr;
int lower, upper, step;

lower=0;
upper=300;
step=20;
celsius=lower;

while (celsius<=upper)
{
fahr=(celsius*1.8)+32;
printf("%.0f %.6f\n", celsius, fahr);
celsius=celsius+step;
}
}


