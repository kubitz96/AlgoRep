#include<stdio.h>

int main()
{
    int x, i, sum = 0;

    printf("Inserire quanti Interi\n");
    scanf("%d", &i);

    puts("Inserire Interi");

    while(i > 0){
        scanf("%d", &x);
        sum += x;
        --i;
    }

    printf("%d", sum);
}