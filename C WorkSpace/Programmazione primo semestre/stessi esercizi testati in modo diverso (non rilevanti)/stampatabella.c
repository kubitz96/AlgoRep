#include<stdio.h>

int main()
{
    int righe = 4;
    int colonne = 8;
    int n;

    puts("Prima Tabella");

    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            n = i*colonne+j; // metodo per non usare contatore e righe //simile storage mapping function
            printf("%3d", n);
        }
        puts("");
    }
    
    puts("Seconda Tabella");
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            n = j*righe+i; // metodo per non usare contatore e colonne
            printf("%3d", n);
        }
        puts("");
    }
}