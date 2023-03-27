#include<stdio.h>

int main()
{
    int x = 1;
    while( x < 1000000000){
        if( x % 100000000 == 0) printf("%d", x);
        ++x;
    }
}