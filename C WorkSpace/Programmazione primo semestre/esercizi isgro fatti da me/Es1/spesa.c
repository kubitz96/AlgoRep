#include<stdio.h>
#define SCONTOMIN 0.05
#define SCONTOMAX 0.1

int main()
{
    float spesa, sconto;


    printf("A quanto ammonta la spesa: ") ;
    scanf("%f", &spesa ) ;
    if (spesa > 300){
        sconto= spesa*SCONTOMAX ;
        spesa= spesa-sconto ;
    }
    if(spesa>100 && spesa<=300){
        
        sconto= spesa*SCONTOMIN ;
        spesa= spesa-sconto ;
        
    }

    printf("Prezzo finale: %.2f", spesa) ;

    return 0 ;
}