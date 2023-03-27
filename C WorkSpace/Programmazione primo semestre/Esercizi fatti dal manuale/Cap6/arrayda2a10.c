#include<stdio.h>
#define SIZE 5  //Si consiglia di usare costanti simboliche per le dimensioni di array per rendere il programma piu leggibile e modificabile

int main()
{
    int n[SIZE];

    for(size_t i = 0; i < SIZE; ++i)
   {
       n[i]= 2 + 2*i;
   }

   printf("%s%13s\n", "Elements", "Value");

    for(size_t i = 0; i < SIZE; ++i)
    {
        printf("%7u%13d\n", i, n[i]);
    }
}