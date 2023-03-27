#include<stdio.h>
#include<stdlib.h>                          //programma che calcola numero conto minimo massimo somma media e li incolonna

int main()
{
    double x, min, max, sum, avg ;
    int cnt = 1 ;

    if(scanf("%lf", &x) != 1){
        printf("errore") ;
        exit(1) ;
    }

    min = max = sum = avg = x ; //va messo dopo lo scan perché se x non ha valore non sto assegnando nessun valore a tutti gli altri

    printf("%9s%9s%9s%9s%9s%9s\n", "NUMERO", "CONTO", "MINIMO", "MASSIMO", "SOMMA", "MEDIA") ;
    printf("%9s%9s%9s%9s%9s%9s\n", "------", "-----", "------", "-------", "-----", "-----") ;
    printf("%9.2lf%9d%9.2lf%9.2lf%9.2lf%9.2lf\n", x, cnt, min, max, sum, avg) ;

    while((scanf("%lf", &x) == 1)){
        ++cnt ;
        if(x<min) min = x ;
        else if(x>max) max = x ;
        sum += x ; //sum= sum+x
        avg = sum / cnt ;
        printf("%9.2lf%9d%9.2lf%9.2lf%9.2lf%9.2lf\n", x, cnt, min, max, sum, avg) ;
    }
    return 0 ;
}