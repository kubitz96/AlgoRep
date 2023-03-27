#include<stdio.h>
#include<math.h>

int main()
{
    double x, y;

    puts("Inserire base e esponente");
    scanf("%lf%lf", &x, &y);

    printf("%.2lf", pow(x,y)); //argomenti double

    return 0;
}