#include<stdio.h>

int main()
{
    int x;
    int cnt = 0;
    int sum = 0;

    while(scanf("%d", &x) && x >= 0)
    {
        sum += x;
        if(cnt > 0) printf(" +\n");
        printf("%8d", x);
        ++cnt;
    }

    if(x < 0)
    {
        puts(" =");
        puts("--------");
        printf("%8d", sum);
    }

    return 0;
}