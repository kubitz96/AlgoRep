#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i;
    int totale;

    puts("Inserire Numero Intero");
    scanf("%d", &n);
    if(n == 0){
        printf("!0 = 1");
        exit(1);
    }
    printf("!%d = %d*", n, n);
    totale= n;

    for(i = 1; n > 1; ++i){
        --n;                      //120 5! 5per4per3per2per1
        n != 1 ? printf("%d*", n) : printf("%d\n", n);

        totale *= n;

    }
    printf("Totale %d", totale);
}