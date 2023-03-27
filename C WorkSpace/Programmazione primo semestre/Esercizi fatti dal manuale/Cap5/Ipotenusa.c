#include<stdio.h>
#include<math.h>

double calcipotenusa(double l1, double l2);

int main()
{
    double lato1, lato2;

    printf("Inserire i due lati del triangolo rettangolo\n");
    scanf("%lf%lf", &lato1, &lato2);

    printf("L'ipotenusa e' %.2lf", calcipotenusa(lato1, lato2));

    return 0;
}

double calcipotenusa(double l1, double l2){
    double ipotenusa;

    ipotenusa= sqrt(l1*l1 + l2*l2);

    return ipotenusa;
}
