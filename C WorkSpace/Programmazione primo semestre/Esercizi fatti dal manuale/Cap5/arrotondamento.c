#include<stdio.h>
#include<math.h>

int main()
{
    float x;

    while(scanf("%f", &x) != 0){
        printf("%.2f arrotondato a %.0lf\n", x+.5, floor( x + .5));  //floor arrotonda all'intero + vicino ceil sempre per difetto;
    }
}