#include<stdio.h>

int main()
{
    int x;
    puts("Inserire sequenza di interi");
    scanf("%d", &x);

    for(int i = 1; x != 0; ++i)
    {
        printf("%6d", x);
        scanf("%d", &x);
        if(i % 4 == 0) puts("");
    }
    return 0;
}