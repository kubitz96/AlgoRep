#include<stdio.h>

int main()
{
    int i, n ;
    printf("numero  quadrato  cubo\n") ;

    for(i=0; i<=10;i++){
        n=i;
        printf("%d%10d%9d\n", n, n*n, n*n*n) ;
    }
    return 0 ;
}