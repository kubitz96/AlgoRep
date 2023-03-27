#include<stdio.h>
#define PIGRECO 3.14159

int main()
{
    int r;

    printf("Inserire Raggio ");
    scanf("%d", &r);
    printf("Diametro %d Circonferenza %f Area %f", r+r, 2*PIGRECO*r, PIGRECO*r*r);

    return 0 ;
}