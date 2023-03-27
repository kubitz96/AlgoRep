#include<stdio.h>
#define SIZE 5

int main()
{
    int n[SIZE];

    for(size_t i = 0; i < SIZE; ++i)
    {
        scanf("%d", &n[i]);
    }

    printf("%s%13s%20s\n", "Elemento", "Valore", "Istogramma");

    for(size_t j = 0; j < SIZE; ++j)
     {
         printf("%8d%13d%10c", j, n[j], ' ');
            for(int m = 0; m < n[j]; ++m)
            {
                printf("%c", '*');
            }
            puts("");
     }
}