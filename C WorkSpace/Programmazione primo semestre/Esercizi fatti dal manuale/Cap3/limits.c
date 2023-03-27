#include<stdio.h>
#include<limits.h>

int main()
{
    printf("%d\n%d\n%u", INT_MIN, INT_MAX, UINT_MAX) ; //operare oltre questi valori con interi crea un overflow aritmetico
}