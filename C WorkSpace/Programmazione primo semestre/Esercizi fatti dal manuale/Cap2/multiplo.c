#include<stdio.h>

int main()
{
    int a, b;

    printf("Inserisci due Interi ") ;
    scanf("%d%d", &a, &b) ;

    if(a % b == 0) printf("%d e' multiplo di %d", a, b) ;
    if(a % b != 0) printf("%d non e' multiplo di %d", a, b) ;

    return 0 ;
}