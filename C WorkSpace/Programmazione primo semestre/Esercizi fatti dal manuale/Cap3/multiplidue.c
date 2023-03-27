#include<stdio.h>

int main()
{
    int x;

    for(x = 1; x > 0; ++x) if(x % 2 == 0) printf("%d\n", x); //attenzione ciclo infinito
}