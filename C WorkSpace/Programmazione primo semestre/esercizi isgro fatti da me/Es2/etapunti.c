#include<stdio.h>
#include<stdlib.h>

#define PUN10 10
#define PUN20 20
#define PUN30 30

int main()
{
    unsigned int eta, punti;

    printf("Eta' --> ");
    while(scanf("%d", &eta) != EOF ){

        if(scanf("%d", &eta) != 1) {
            printf("Errore");
            exit(1);
        }

        if((eta > 15 && eta <= 35) || (eta >= 49 && eta <= 59) ) punti=PUN10;
        else if((eta >= 36 && eta <= 48) || (eta >= 76 && eta <= 80)) punti=PUN30;
        else punti=PUN20;
        printf("Punti --> %d \n\n", punti);
        printf("Eta' --> ");
    }
}
