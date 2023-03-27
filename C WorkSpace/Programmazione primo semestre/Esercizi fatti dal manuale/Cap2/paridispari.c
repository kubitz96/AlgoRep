#include<stdio.h>

int main()
{
    int a;

    printf("Inserire Intero ") ;
    scanf("%d", &a) ;

    if(a % 2 == 0) printf("%d e' pari", a) ;
    if(a % 2 != 0) printf("%d e' dispari", a) ;

    return 0 ;
}