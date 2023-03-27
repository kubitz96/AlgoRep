#include<stdio.h>

int main()
{
    int i, x, j;

    printf("Inserisci 5 numeri Interi tra 1 e 30\n");

    for(i = 1; i <= 5; ++i){
        scanf("%d", &x);
        for(j = 1; j <= x; ++j) printf("*");
        puts("");
    }
}