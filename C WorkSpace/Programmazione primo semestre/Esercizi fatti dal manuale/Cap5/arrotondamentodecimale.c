#include<stdio.h>
#include<math.h>
double roundToInteger(double number);
double roundToTenths(double number);
double roundToHundreths(double number);
double roundToThousandths(double number);

int main ()
{
    double n;   //7.4673
    unsigned int cnt;
    printf("Quanti numeri vuoi processare?\n");
    scanf("%u", &cnt);

    for( int i = 1; i <=cnt; ++i){
        printf("Inserire numero\n");
        scanf("%lf", &n);
        printf("%10.4lf%10.1lf%10.2lf%10.3lf%10.4lf\n", n, roundToInteger(n), roundToTenths(n), roundToHundreths(n), roundToThousandths(n) );

    }
}

double roundToInteger(double number){
    number= floor(number+0.5);
    return number;
}

double roundToTenths(double number){
    number= floor(number*10+0.5)/10;
    return number;
}

double roundToHundreths(double number){
    number= floor(number*100+0.5)/100;
    return number;
}

double roundToThousandths(double number){
    number= floor(number*1000+0.5)/1000;
    return number;
}