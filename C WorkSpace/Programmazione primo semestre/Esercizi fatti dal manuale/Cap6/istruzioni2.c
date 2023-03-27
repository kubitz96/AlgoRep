#include<stdio.h>
#define     SIZE        3

int main()
{
    int table[3][3];
    int total = 0;

    for (size_t i = 0; i < SIZE; ++i)
    {
        for (size_t j = 0; j < SIZE; ++j)
        {
            ++total;
        }
        
    }
    for (size_t x = 0; x < SIZE; ++x)
    {
        for (size_t y = 0; y < SIZE; ++y)
        {
            table[x][y] = x + y;
        }
        
    }
    printf("Total: %d Elements\n", total);

    for (size_t x = 0; x < SIZE; ++x)
    {
        for (size_t y = 0; y < SIZE; ++y)
        {
            printf("%4d", table[x][y]);
        }
        puts("");
    }
    
}