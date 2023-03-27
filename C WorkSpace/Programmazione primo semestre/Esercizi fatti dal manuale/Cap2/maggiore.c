#include<stdio.h>

int main()
{
    int a, b, max;
    printf("inserire due interi ") ;
    scanf("%d%d", &a, &b) ;
    if(a==b) printf("i numeri sono uguali") ;
    if(a>b) printf("%d e' maggiore", a) ;
    if(a<b) printf("%d e' maggiore", b) ;

    return 0 ;
}