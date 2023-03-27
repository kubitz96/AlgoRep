#include<stdio.h>
// programma che controlla il primo numero potenza di 3 maggiore di cento 243
int main()
{
    int x = 3 ;

    while(x <= 100){
        x *= 3 ;
    }

    printf("%d", x) ; 
}