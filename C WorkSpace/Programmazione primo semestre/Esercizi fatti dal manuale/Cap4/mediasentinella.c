#include<stdio.h>

int main()
{
    int x, i = 0; 
    int sum = 0;
    
    puts("Inserire Intero");
    scanf("%d", &x);

    while(x != 9999){
        sum += x;
        ++i;        //ricordarsi che la i vieni incrementata prima dello scanf del 9999
        puts("Inserire Intero");        //quando si fa la sentinella lo scanf va per ultimo nel while 
        scanf("%d", &x);
    }

    printf("Media = %.2f", (float)sum/i);
}