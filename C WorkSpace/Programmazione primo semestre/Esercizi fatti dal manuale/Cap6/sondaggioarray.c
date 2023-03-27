#include<stdio.h>
#define SIZE_VOTI 10
#define SIZE_FREQUENZA 11

int main()
{
    int voti[SIZE_VOTI];
    int frequenza[SIZE_FREQUENZA] = {0};

    for(size_t i = 0; i < SIZE_VOTI; ++i)
    {
        printf("Inserisci Voto\n");
        scanf("%d", &voti[i]);
    }

    printf("%s%13s\n", "Voti", "Frequenza");

    for(size_t j = 0; j < SIZE_VOTI; ++j)
    {
        ++frequenza[voti[j]];
    }

    for(size_t r = 1; r <   SIZE_FREQUENZA; ++r)
    {
        printf("%7d%13d\n", r, frequenza[r]);
    }
    
    return 0;
}