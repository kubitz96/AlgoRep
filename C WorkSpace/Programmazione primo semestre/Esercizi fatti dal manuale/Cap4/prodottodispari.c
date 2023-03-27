#include<stdio.h>

int main()
{
    int x, prod = 1;

    for(x = 1; x <= 15; x += 2){
        prod *= x;
    }
    printf("%d", prod);
}