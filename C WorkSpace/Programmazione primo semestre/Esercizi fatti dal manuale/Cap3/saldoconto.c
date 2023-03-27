#include<stdio.h>

/*numero conto, saldo iniziale, totale addebiti finemese, totalecrediti, limite concesso
il programma deve leggere tali dati e calcolare il nuovo saldo(=saldoiniziale + addebiti - crediti)
e determinare se il saldo supera il limite. se viene superato stamp num, limite,saldonuovo + limcredsup*/


int main()
{
    int n;
    float saldo, totsal, totdeb, totcre, limit;

    printf("Inserire Numero Conto\n");
    scanf("%d", &n);

    while(n != -1){
        printf("Inserire Saldo Iniziale\n");
        scanf("%f", &saldo);
        printf("Inserire Totale addebiti\n");
        scanf("%f", &totdeb);
        printf("Inserire Totale crediti\n");
        scanf("%f", &totcre);
        printf("Inserire Limite credito\n");
        scanf("%f", &limit);

        saldo += totdeb - totcre;
        if(saldo > limit) puts("Limite Superato\n");
            printf("Inserire Numero Conto\n");
            scanf("%d", &n);
    }
}