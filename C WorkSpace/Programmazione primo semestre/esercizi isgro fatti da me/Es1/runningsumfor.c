#include<stdio.h>
#include<stdlib.h>                          //programma che calcola numero conto minimo massimo somma media e li incolonna

int main()
{
    double x, min, max, sum, avg ;
    int i ;

    if(scanf("%lf", &x) != 1){ //primo scanf chiesto un unica volta a inizio programma (messo in condizione di un if è come implementare uno scanf direttamente)
        printf("errore") ;
        exit(1) ;
    }

    min = max = sum = avg = x ; //va messo dopo lo scan perché se x non ha valore non sto assegnando nessun valore a tutti gli altri

    printf("%9s%9s%9s%9s%9s%9s\n", "NUMERO", "CONTO", "MINIMO", "MASSIMO", "SOMMA", "MEDIA") ;
    printf("%9s%9s%9s%9s%9s%9s\n", "------", "-----", "------", "-------", "-----", "-----") ;
    printf("%9.2lf%9d%9.2lf%9.2lf%9.2lf%9.2lf\n", x, 1, min, max, sum, avg) ;

    for(i = 2; scanf("%lf", &x) == 1; ++i){ //secondo scanf posto come seconda condizione ciclica del for viene eseguito dopo il primo e non è lo stesso, viene ripetuto ogni volta
        if(x<min) min = x ;
        else if(x>max) max = x ;
        sum += x ; //sum= sum+x
        avg = sum / i;
        printf("%9.2lf%9d%9.2lf%9.2lf%9.2lf%9.2lf\n", x, i, min, max, sum, avg) ;
    }
    return 0 ;
}