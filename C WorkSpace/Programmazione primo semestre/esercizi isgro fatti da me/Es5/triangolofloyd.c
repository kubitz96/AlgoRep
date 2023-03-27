#include<stdio.h>

int main()
{
    int j, i, n;
    int cnt = 0;

    puts("Inserire quante righe per triangolo di floyd stampare");
    scanf("%d", &n);

    for( i = 1; i <= n; ++i)
    {
        for(j = 1; j<=i; ++j)
        {
        ++cnt;
        printf("%3d", cnt);
        }
        puts("");
    }

    return 0;
}