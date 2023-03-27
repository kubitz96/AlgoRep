#include<stdio.h>

int trovamax(int x, int y, int z);

int main()
{
    int a, b, c, max;

    printf("Inserisci 3 interi\n");
    scanf("%d%d%d", &a, &b, &c);

    max= trovamax(a, b, c);

    printf("%d", max);
}

int trovamax(int x, int y, int z){

    int max;

    if( x > y && x > z) max= x;
    if( y > x && y > z) max= y;
    if( z > x && z > y) max= z;

    return max;
}