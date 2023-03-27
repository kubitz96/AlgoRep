#include<stdio.h>

int mcd(int x, int y);
void swap(int *p, int *q);
int mcm(int x, int y);

int main()
{
    int x,  y;
    int ris;
    int ris2;

    puts("inserire due numeri interi");
    scanf("%d%d", &x, &y);

    ris = mcd(x, y);
    ris2 = mcm(x, y);

    printf("MCD = %d\n", ris);
    printf("mcm = %d", ris2);
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int mcd(int x, int y)
{
    if(y > x) swap(&x, &y);

    if(x % y == 0) return y;

    return mcd(y, (x % y));
}

int mcm(int x, int y)
{
    if( y > x) swap(&x, &y);

    if(x % y == 0) return x;

    return mcm(x+x, y);
}