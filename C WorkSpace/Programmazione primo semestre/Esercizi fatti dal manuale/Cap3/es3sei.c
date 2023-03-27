#include<stdio.h>

int main()
{
    unsigned int x, y;
    unsigned int i = 1;
    unsigned int power = 1;
    
    scanf("%u%u", &x, &y);
    power *= i;
    ++i;
    while(i <= y) printf("%u", power);
    
}