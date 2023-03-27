#include<stdio.h>
#include<stdlib.h>

void modificarray(int *p, int n);

int main()
{
    int *a;

    a = malloc(5*sizeof(int));

    for (size_t i = 0; i < 5; i++)
    {
        a[i] = i + 1;
    }

    for (size_t j = 0; j < 5; ++j)
    {
        printf("%2d", a[j]);
    }

    puts("");
    
    modificarray(a,5);
    
    for (size_t j = 0; j < 5; ++j)
    {
        printf("%2d", a[j]);
    }
}

void modificarray(int *p, int n)
{
    p[2] = 7;
}