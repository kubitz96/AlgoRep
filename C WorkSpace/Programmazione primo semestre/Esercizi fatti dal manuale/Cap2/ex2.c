//questo programma calcola il prodotto tra tre interi
#include<stdio.h>

int main()
{
    int x, y, z ;
    int prodotto ;
    printf("inserire 3 interi: ") ;
    scanf("%d%d%d", &x, &y, &z ) ;

    prodotto = x * y * z ;
    printf("il prodotto e' %d", prodotto) ;

    return 0 ;

}