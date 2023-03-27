#include<stdio.h>

int digitalroot(int n);

int main()
{
    int n;

    puts("Inserire numero");
    scanf("%d", &n);

    printf("Radice Digitale = %d", digitalroot(n));

    return 0;
}

int sumdigit(int n)
{
    if(n % 10 == n) return n;
    return n%10 + sumdigit(n/10);
}

int digitalroot(int n) //sommo le cifre totali del numero, poi ottenuta la somma se ha piu di una cifra applica di nuovo la somma delle cifre, se la cifra è una solo ritorno quella cifra
{
    if(sumdigit(n) < 10) return sumdigit(n);
    return digitalroot(sumdigit(n));
}