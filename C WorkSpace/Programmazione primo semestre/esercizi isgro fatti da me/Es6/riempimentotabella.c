#include<stdio.h>

int main()
{
    int i, j;
    int righe, colonne;
    int cnt = 0;

    puts("Inserire numero righe e colonne");
    scanf("%d%d", &righe, &colonne);

    for(i = 1; i <= righe; ++i)
    {
        for(j = 1; j <= colonne; ++j)
        {
            printf("%6d", cnt);
            ++cnt;
        }
        puts("");
    }
}