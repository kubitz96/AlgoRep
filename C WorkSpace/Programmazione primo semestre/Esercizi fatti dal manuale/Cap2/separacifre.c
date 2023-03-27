#include<stdio.h>

int main()
{
    int a ;

    printf("Inserire Intero a 5 cifre ") ;
    scanf("%d", &a) ;

    int resto;
    printf("%d   ", a/10000);
    resto= a % 10000 ;

    printf("%d   ", resto/1000);
    resto= a % 1000 ;

    printf("%d   ", resto/100);
    resto= a % 100 ;

    printf("%d   ", resto/10);
    resto= a % 10 ;
    
    printf("%d   ", resto);
 
    return 0 ;
}