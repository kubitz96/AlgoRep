#include<stdio.h>

int main()
{
    int x, sum = 0;

    for(x = 2; x <= 100; x += 2){
        sum += x;
    }
    printf("totale somma %d", sum);

    return 0;
}