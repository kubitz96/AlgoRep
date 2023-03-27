#include<stdio.h>

int main()
{
    int x, y, temp;

    x = 7;
    y = 5;

    temp = x;
    x = y;
    y = temp;

    printf("%d%2d\n", x, y); // 5 7

    x = x + y; //5+7 x= 13
    y = x - y; //13 - 7 = 5
    x = x - y; //13 - 5 = 7

    printf("%d%2d\n", x, y); // 7 5

}