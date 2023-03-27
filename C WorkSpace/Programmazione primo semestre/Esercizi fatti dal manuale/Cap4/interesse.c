#include<stdio.h>

int main()
{
    double a, p, r; //a=denarototale p=denaroiniziale r=tassoannualeinteresse n=anni
    unsigned int n, anni = 1; 
    a = 0;                  //calcolare a per ogni singolo anno

    puts("Inserire investimento iniziale");
    scanf("%lf", &p);
    puts("Inserire tasso previsto");
    scanf("%lf", &r);
    puts("Inserire anni di calcolo");
    scanf("%u", &n);
    printf("%4s%21s", "Anno", "Deposito Totale\n");
    for(; n != 0; --n){
            a = p*(1+r);
            printf("%2u%19.2lf$\n", anni, a);
            p = a;
            ++anni;
    }


    }