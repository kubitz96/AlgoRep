#include<stdio.h>
#define COLUMN 3
#define ROW 2

void printBidimensionalArray(int a[][COLUMN]);
int main()
{
    int b[ROW][COLUMN] = {{1,2,3}, {4,5,6}};
    int c[ROW][COLUMN] = {{1,2}, {4}};
    int total = 0;

    puts("I valori nell' array b sono per riga:");
    printBidimensionalArray(b);
    puts("I valori nell' array c sono per riga:"); // gli elementi non specificati vengono inizializzati a 0
    printBidimensionalArray(c);

    puts("Azzero i valori nella prima riga del array c:");
    for (size_t i = 0; i < COLUMN; ++i)
    {
        c[0][i] = 0;
    }
    printBidimensionalArray(c);

    puts("Calcolo il totale dei valori nell' array b :");
    for (size_t i = 0; i < ROW; ++i)
    {
        for (size_t j = 0; j < COLUMN; ++j)
        {
            total += b[i][j];
        }
        
    }
    printf("Total: %d", total);
    
    
    return 0;
}

void printBidimensionalArray(int a[][COLUMN]) // il primo indice non ha bisogno di essere esplicitato
{
    for (size_t r = 0; r < ROW; ++r)
    {
        for (size_t c = 0; c < COLUMN; ++c)
        {
            printf("%2d", a[r][c]);
        }
        puts("");
    }
    
}

