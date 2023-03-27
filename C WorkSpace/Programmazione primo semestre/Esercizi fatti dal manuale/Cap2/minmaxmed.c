#include<stdio.h>

int main()
{
    int a, b, c ;
    int sum, avg, pro ;

    printf("Inserisci tre interi differenti: ") ;
    scanf("%d%d%d", &a, &b, &c) ;
    sum= a + b + c ;
    avg= sum / 3 ;
    pro= a * b * c ;
    printf("Somma %d\nMedia %d\nProdotto %d\n", sum, avg, pro) ;

    int min ;

    min = a;
    if(b < min) {
        min= b;
    }
    if(c < min){
        min= c;
    }
    printf("Minimo %d\n", min) ;

    int max; 

    max = a;
    if(b > max){
        max= b ;         //ricordarsi che a max viene associato il valore di b quindi si ragiona da destra a sinistra(b= max è come fare b che assume il valore di a)
    }
    if(c > max){
         max= c;
    }

    printf("Massimo %d", max) ;

    return 0 ;

}