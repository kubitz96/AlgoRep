#include<stdio.h>

int main()
{
    int i, j;
    int righe, colonne;
    int cnt = 4;

    puts("Inserire numero righe e colonne");
    scanf("%d%d", &righe, &colonne);

    for(i = 0; i < righe; ++i)
    {
        for(j = 0; j < colonne; ++j)
        {
            if(j == 0) printf("%d", i);
            else 
            {
                printf("%6d", i+cnt);
                cnt += 4;
            }
        }
        cnt = 4;
        puts("");
    }
}