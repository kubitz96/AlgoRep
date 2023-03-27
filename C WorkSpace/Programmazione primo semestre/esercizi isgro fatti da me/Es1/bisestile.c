// un anno è bisestile ogni 4 anni tranne i secolari multipli di 400 (%400)
#include<stdio.h>

int main()
{
    int anno;

    printf("anno --> ");
    while(scanf("%d", &anno) != EOF){
        if(anno % 400 == 0) printf("L'anno %d non e' bisestile\n", anno);
        else if(anno % 4 == 0 /*|| anno % 100 == 0 facoltativo perche 100 e multiplo di 4*/) printf("l'anno %d e' bisestile\n", anno);
        else printf("L'anno %d non e' bisestile\n", anno);
    }
}