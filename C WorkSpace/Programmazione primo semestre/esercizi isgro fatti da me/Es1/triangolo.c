#include<stdio.h>

int main()
{
    int a, b, c ;
    printf("lato a --> ") ;
    scanf("%d", &a) ;
    printf("lato b --> ") ;
    scanf("%d", &b) ;
    printf("lato c --> ") ;
    scanf("%d", &c) ;

    if(a==b && b==c) printf("Il triangolo e' equilatero") ;
    else if(a==b || b==c || a==c) printf("Il triangolo e' isoscele") ;
    else printf("Il triangolo e' scaleno") ;

    return 0 ;
}