#include<stdio.h>

int main()
{
      int n[5] = {32, 27, 64, 18, 95}; // se ci sono meno iniziallizatori rispetto agli elementi gli altri elementi vengono automaticamente inizializzati a 0, es: n[5]= {0} stampa tutti 0

    printf("%s%13s\n", "Element", "Value");

    for(size_t i = 0; i < 5; ++i)      //size_t è un tipo di dato che rappresenta un tipo intero senza segno se non ce in stdio.h si usa stddef
    {
        printf("%7u%13u\n", i, n[i]);
    }

    return 0;  
}