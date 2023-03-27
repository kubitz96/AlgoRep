#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE_DADO 7

int main()
{
    unsigned int frequenza[SIZE_DADO] = {0};  // ricordati sempre di inizializzare l'array dove bisogna contare dei valori STRONZO

    srand(time(NULL));

    for (unsigned int tiro = 1; tiro <= 60000000; ++tiro)
    {
        size_t faccia= 1 + rand() % 6;
        ++frequenza[faccia];
    }
    
    printf("%s%13s\n", "Faccia", "Frequenza");

    for (size_t faccia = 1; faccia < SIZE_DADO; ++faccia)
    {
        printf("%7d%17d\n", faccia, frequenza[faccia]);
    }
    
}