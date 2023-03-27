#include<stdio.h>
#include<stdlib.h>

void swapint(int a, int b);
void swapptr(int *p, int *q);

int main()
{
    int x = 3;
    int y = 5;

    puts("Valori Iniziali");
    printf("%d %d\n", x, y);

    puts("Valori Scambiati con swapint");
    swapint(x,y);               //scambio di variabili avviene solo all'interno di swapint

    puts("Valori fuori swapint");
    printf("%d %d\n", x, y);

    puts("Valori Scambiati con swapptr");
    swapptr(&x,&y);             // scambio di indirizzi permette una vera modifica delle variabili semplicemente scambiando gli indirizzi
    printf("%d %d\n", x, y);

    puts("Valori fuori swapptr");
    printf("%d %d\n", x, y);
}

void swapint(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n", a, b);
}

void swapptr(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}