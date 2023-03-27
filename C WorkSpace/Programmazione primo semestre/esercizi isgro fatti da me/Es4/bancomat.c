#include<stdio.h>

int main()
{
    int x;
    int cnt50, cnt20;

    printf("somma --> ");
    scanf("%d", &x);

    cnt50= x / 50;
    cnt20= (x % 50) / 20;
    x= cnt20*20 + cnt50*50;

    if(cnt50 >0) printf("Banconote da 50: %d\n", cnt50);
    if(cnt20 >0) printf("Banconote da 20: %d\n", cnt20);
    printf("Somma Erogata --> %d", x);

}