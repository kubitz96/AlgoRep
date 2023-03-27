/* utente inserisce durata in secondi e calcola minuti e ore*/

#include<stdio.h>
#define SECINMINUTO 60
#define SECINORA    3600

int main()
{
    int secondi, minuti, ore;

    printf("Tempo --> ");
    scanf("%d", &secondi);

    ore= secondi/SECINORA;
    secondi= secondi % SECINORA;
    minuti= secondi/SECINMINUTO;
    secondi= secondi % SECINMINUTO;

    printf("%dh %dm %ds", ore, minuti, secondi);

}