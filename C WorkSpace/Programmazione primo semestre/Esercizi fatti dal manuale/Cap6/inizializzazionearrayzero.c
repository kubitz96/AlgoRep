#include<stdio.h>

int main()
{
    int n[5];

    for(size_t i = 0; i < 5; ++i)          //inizializzare il vettore a 0 poiche contiene valori spazzatura
    {
        n[i] = 0;
    }

    printf("%s%13s\n", "Element", "Value");

    for(size_t i = 0; i < 5; ++i)      //size_t è un tipo di dato che rappresenta un tipo intero senza segno se non ce in stdio.h si usa stddef
    {
        printf("%7u%13u\n", i, n[i]);
    }

    return 0;
}