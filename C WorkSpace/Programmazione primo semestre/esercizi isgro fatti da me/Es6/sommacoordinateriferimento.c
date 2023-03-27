#include<stdio.h>

void sommapunti( int x1, int y1, int x2, int y2, int *x, int*y); //se passo gli indirizzi come parametri ai puntatori , scrivero dei valori alle variabili simulando il passaggio per riferimento

int main()
{
    int x1, y1, x2, y2, xs, ys;
    x1=x2=2;
    y1=y2=1;
    sommapunti(x1, y1, x2, y2, &xs, &ys);

    printf("%d %d", xs, ys);
}

void sommapunti( int x1, int y1, int x2, int y2, int*x, int*y)
{
    *x= x1 + x2;
    *y= y1 + y2;
}