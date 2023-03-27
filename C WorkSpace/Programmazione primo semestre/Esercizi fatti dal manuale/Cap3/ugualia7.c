#include<stdio.h>

int main()
{
    int x, cnt = 0, dig, temp;

    puts("Inserire quante cifre");
    scanf("%d", &dig);

    puts("Inserire Numero Intero");
    scanf("%d", &x);

    while(dig  > 0) {
        temp = x / 10;
        if(x % 10 == 7) ++cnt;
        x = temp;
        --dig;
    }

    printf("%d", cnt);
}