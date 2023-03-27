#include<stdio.h>

int main()
{
    int x, sum = 0;

    for(x = 2; x <= 30; x += 2){
        sum += x;
    }
    printf("%d", sum);
}