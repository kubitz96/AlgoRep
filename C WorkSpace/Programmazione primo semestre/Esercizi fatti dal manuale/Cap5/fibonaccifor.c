#include<stdio.h>

int main()
{
    int i, k, sum;
    int primo = 0, secondo = 1;

    printf("quanti elementi di fibonacci calcolare?\n");
    scanf("%d", &k);

    if(k == 1) puts("0");
    else if (k > 1){
        printf("fibonacci(%d)=%5d%5d", k, 0, 1);
        for(i = 2; i <= k; ++i){
            sum= primo + secondo;
            printf("%5d", sum);
            primo= secondo;
            secondo= sum;
            
        }
    }
}
