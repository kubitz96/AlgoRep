#include<stdio.h>
#include<limits.h>

int main()
{
    int x, i = 1;
    int min = INT_MAX;
    int max = INT_MIN;
    int sumd, sump, sumt;
    sumd = sump = sumt = 0;

    while(scanf("%d", &x) && x != 0)
    {
        if(x < min) min= x;
        if(x > max) max= x;
        if(i % 2 == 0) sump += x; 
        else sumd += x;
        sumt += x;
        ++i;
    }
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
    printf("Somma dispari = %d\n", sumd);
    printf("Somma pari = %d\n", sump);
    printf("Somma totale = %d\n", sumt);
}