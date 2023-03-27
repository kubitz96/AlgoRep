#include<stdio.h>
#include<stdlib.h>

int main()
{
    float galloni, totgal, totm, miles; 
    totm=totgal=0; //si consiglia di inizializzare i totali a 0 per essere sicuri che non si hanno errori
    int i = 0; //i contatore pieni //in automatico il compilatore le inizializza a 0 ma meglio essere precisi

        printf("Inserisci Galloni --> ");
        scanf("%f", &galloni);

    while (galloni !=-1){
        if(galloni ==-1 ) return galloni;
        printf("Inserisci Miglia --> ");
        scanf("%f", &miles);
        printf("Il rapporto miglia/galloni e' stato di %f\n", miles/galloni);

        totgal += galloni;
        totm += miles;
        ++i;
        printf("Inserisci Galloni --> ");//bisogna inserire la lettura a fine ciclo per usare la sentinella
        scanf("%f", &galloni);
    }
    printf("In %d pieni, la Media complessiva miglia galloni %f", i, totm/totgal);
    return 0;
}