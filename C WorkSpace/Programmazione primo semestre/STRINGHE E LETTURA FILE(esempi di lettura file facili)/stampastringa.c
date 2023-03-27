#include<stdio.h>           //pag 464 manuale
#include<stdlib.h>
#include<string.h>

int main()
{
    
    char stringa[100]; //stringa di 100 caratteri vuota;

    puts("Scrivi Stringa");
    scanf("%s", stringa);

    puts("Prima stampa");
    printf("%s\n\n", stringa);

    puts("Stampa al Contrario");
    for (int i = strlen(stringa) ; i >= 0 ; --i)
    {

        printf("%c", stringa[i]);
    }
    
    return 0;
}