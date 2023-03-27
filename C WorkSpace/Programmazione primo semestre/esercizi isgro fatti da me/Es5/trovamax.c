#include<stdio.h>
#include<limits.h>

int trovamax(int a, int b, int c);

int main()
{
    int x, y, z;

    scanf("%d%d%d", &x, &y, &z);

    printf("%d", trovamax(x, y, z));
}

int trovamax(int a, int b, int c)
{
    int max;
    max= a;
    if(a < b  && b > c) max= b;
    else if(a < c  && c > b) max= c;
}