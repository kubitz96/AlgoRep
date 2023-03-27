#include<stdio.h>

int main()
{
    unsigned int x, sum = 0;

    for(x = 1; x <= 99; ++x){
        if((x % 2) != 0) sum += x;
    }

    printf("%u", sum);
    return 0;
}