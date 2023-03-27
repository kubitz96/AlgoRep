#include<stdio.h>

int main()
{
    int x, y ;

    printf("Inserisci due numeri Interi ") ;
    scanf("%d%d", &x, &y) ;

    if(x==y) printf("i due numeri sono uguali") ; //se un valore e uguale a un altro valore si scrive == oppure nel if avviene l'assegnazione
    (x<y) ? printf("%d e' minore di %d", x, y) : printf("%d e' maggiore di %d", x, y) ;

    return 0 ;
}