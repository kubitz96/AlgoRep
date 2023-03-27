#include<stdio.h>
#include<stdlib.h>

int main()
{
    int voto, somma ;
    float media ;
    unsigned int i, esami ; //valori sicuramente positivi posso mettere unsingned int nell'altro caso i= numero voti
    somma = 0 ;             //per unsigned int si usa %u

    /*printf("Quanti esami --> ") ; qui la i inizializzata a 1 e la condizione e i < esami
    scanf("%d", &esami) ;*/
    puts("Inserire Voto") ;             //prima fuori poi dentro il for come ultima lettura per fare sentinella
    scanf("%d", &voto) ;

    for(i = 0 ; voto != -1 ; ++i) {                   //voto = valore sentinella
        somma += voto ;
        puts("Inserire Voto") ;
        scanf("%d", &voto) ;
    }

    //conversione esplicita, senza di essa somma fratto esami da un tipo intero perche entrambi interi
    media= (float) somma/i ;                 //23 25 27 28 = 25,75 senza la conv exp da 25
    printf("Media--> %.2f", media) ; // il punto due è la precisione che di default è 6

   return 0 ;

}