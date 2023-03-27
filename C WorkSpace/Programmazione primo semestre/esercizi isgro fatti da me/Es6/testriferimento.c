#include<stdio.h>

void riferimento(int a, int b, int*c, int*d);

int main()
{
    int x = 5;
    int y = 7;

    printf("%d %d\n", x, y);
    riferimento(x, y, &x, &y);
    printf("%d %d", x, y);
}

void riferimento(int a, int b, int*c, int*d)
{
    *c= b;
    *d= a;
}