#include<stdio.h>

int main()
{
    int x, i;

    puts("Inserire Intero");
    scanf("%d", &x);
    printf("divisori di %d: ", x);

    for(i = 1; i <= x; ++i)
    {
        if(x % i == 0) printf("%4d", i);
    }
}