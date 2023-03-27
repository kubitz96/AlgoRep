#include<stdio.h>
#include<math.h>

int main()
{
    int bit, i; 
    int decimale = 0;

    puts("Inserire bit totali");
    scanf("%d", &bit);
    printf("Inserire valori tra 0 o 1\n");

    for(i = bit-1; i >= 0; --i)
    {  
        scanf("%d", &bit);
        decimale += pow(2,i)*bit; 
    }

    printf("Conversione Decimale: %d", decimale);

    return 0;
}