#include<stdio.h>

int main()
{
    int i, n = 1;
    printf("N\t10*n\t100*N\t1000*N\n\n");

    for(i = 1; i <= 10; ++i){
       printf("%d\t%d\t%d\t%d\t\n", n, n*10, n*100, n*1000);
       ++n;
    }
}