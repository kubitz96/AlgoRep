#include<stdio.h>

int main()
{
    float prezzo , scontato ;
    int sconto ;

    printf("Prezzo --> ") ;
    scanf("%f", &prezzo ) ;
    printf("Sconto --> ") ;
    scanf("%d", &sconto ) ;

    scontato= (prezzo/100)*sconto ;
    prezzo= prezzo - scontato ;

    printf("Costo = %.2f", prezzo) ;

    return 0 ;

}