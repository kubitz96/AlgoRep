#include<stdio.h>   //%p conversione indirizzi, gli array interi vengono passati per riferimento(oppure per valore con le struct) i singoli elementi per valore come le variabili.

int main()
{
    char array[5];

    printf("array = %p\n&array = %p\n&array[0] = %p", array, &array, &array[0]);
}