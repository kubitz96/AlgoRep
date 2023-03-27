//dati due interi calcola somma, differenza, prodotto, quoziente, resto
#include<stdio.h>

int main()
{   
    int a, b ;
    int sum, dif, prod, quo, resto ;
    printf("Inserisci due interi ") ;
    scanf("%d%d", &a, &b) ;

    sum= a + b ;
    dif= a - b ;
    prod= a * b ;
    quo= a / b ;
    resto= a % b ;

    printf("la somma e' %d\nla differenza e' %d\nil prodotto e' %d\nil quoziente e' %d\nil resto e' %d\n", sum, dif, prod, quo, resto) ;

    return 0 ;

}