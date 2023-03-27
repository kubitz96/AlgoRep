#include<stdio.h>
#define SIZE_ARRAY 3
// gli array statici sono automaticamente iniziallizati a 0 e mantengono le modifiche dei valori quando vengono chiamati

void staticArrayInit(void);
void automaticArrayInit(void);

int main()
{
    puts("Prima chiamata di funzione");
    staticArrayInit();
    automaticArrayInit();

    puts("Seconda chiamata di funzione");
    staticArrayInit();
    automaticArrayInit();

}

void staticArrayInit(void)
{
    static int array1[SIZE_ARRAY];

    puts("Valori presenti negli elementi del array 1");
    for (size_t i = 0; i < SIZE_ARRAY; ++i)
    {
        printf("array1[%u] = %d\n", i, array1[i]);
    }
    
    puts("Modifica dei valori di 5");
    
    for (size_t i = 0; i < SIZE_ARRAY; ++i)
    {
        printf("array1[%u] = %d\n", i, array1[i] += 5);
    }
}

void automaticArrayInit(void)
{
    int array2[SIZE_ARRAY] = {1, 2, 3};

    puts("Valori presenti negli elementi del array 2");
    for (size_t i = 0; i < SIZE_ARRAY; ++i)
    {
        printf("array2[%u] = %d\n", i, array2[i]);
    }
    
    puts("Modifica dei valori di 5");
    
    for (size_t i = 0; i < SIZE_ARRAY; ++i)
    {
        printf("array2[%u] = %d\n", i, array2[i] += 5);
    }
}