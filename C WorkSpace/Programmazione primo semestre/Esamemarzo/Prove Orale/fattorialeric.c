#include<stdio.h>

int fattoriale(int n);

int main()
{
    int x;
    int fact;

    puts("inserire numero con il quale eseguire fattoriale");
    scanf("%d", &x);

    fact = fattoriale(x);

    printf("risultato !%d = %d", x, fact);

    return 0;
}

int fattoriale(int n)
{
    
    if(n == 1 || n == 0) return 1;

    return n * fattoriale(n-1);;
}