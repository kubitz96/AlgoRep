#include<stdio.h>
                    //prima legge !(A && B) = !A || !B
                    //seconda legge !(A ||B)= !A && !B
int main()
{
    int x, y, a, b, g, i, j;

    if( (!(x < 5) && !(y >=7)) == !(x < 5 || y >=7) ) puts("a)Vero\n");

    if(!(a == b) || !(g != 5) == (!(a == b) && g != 5))  puts("b)Vero\n");

    if(!((x <= 8) && (y >=4)) == (!(x <= 8) || !(y >=4)) ) puts("c)Vero\n");

    if(!((i > 4) || (j <= 6)) == (!(i > 4) && !(j <= 6)) ) puts("d)Vero\n");
}