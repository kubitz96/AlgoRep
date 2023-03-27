/*
int MCD(int n1, int n2)
{
    int min, max;
    int resto;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
    while((max % min) != 0){
        resto= (max % resto);
        max= min;
        min= resto;
    } 
    return min;
}
*/
#include<stdio.h>

int MCDricorsivo(int x, int y);

int main()
{
    int a, b;

    puts("Inserire 2 numeri Interi");
    scanf("%d%d", &a, &b);

    printf("MCD = %d", MCDricorsivo(a,b));

    return 0;
}

int MCDricorsivo(int x, int y)
{
    if(x % y == 0) return y;
    return MCDricorsivo(y, (x % y));
}