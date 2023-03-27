#include<stdio.h>

int main()
{
    int sum, x;
    x = 1;
    sum = 0;

    while(x <= 10){
    sum += x;
    ++x;
    }
    printf("the sum is %d", sum);

}