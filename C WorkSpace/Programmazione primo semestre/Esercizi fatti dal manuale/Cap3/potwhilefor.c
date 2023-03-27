#include<stdio.h>

int main()
{
    unsigned int x, y;
    unsigned int i = 1;
    unsigned int power = 1;
    
    scanf("%u%u", &x, &y);
    
    while(i <= y) {
        power *= x;
        ++i;
    }
    printf("%u\n", power);

    power = 1;
    for(i = 1; i <= y; ++i){
        power *= x;
    }
    printf("%u", power);
}