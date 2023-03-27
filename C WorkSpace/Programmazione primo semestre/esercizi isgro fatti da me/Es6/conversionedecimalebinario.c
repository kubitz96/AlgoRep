#include<stdio.h>
#include<math.h>

void dectobin(int num, int bit);

int main()
{
    int b, decimale;

    puts("Inserire bit totali");
    scanf("%d", &b);
    printf("Inserire Intero Decimale\n");
    scanf("%d", &decimale);

    printf("Conversione binario :");
    dectobin(decimale,b);

    return 0;
}

void dectobin(int num, int bit)
{
    int i;
    
    for(i = bit-1; i >= 0; --i)
    {
        if(pow(2,i) <= num)
        {
            putchar('1');
            num -= pow(2,i);
        }
        else putchar('0');
    }
}