#include<stdio.h>

int main()
{
    unsigned int x = 1;

    while(x <= 20){
        printf("%u", x);
        if((x % 5) == 0) puts("");
        else printf("\t");
        ++x;
    }
    puts("");
    for(x = 1; x <= 20; ++x){
        printf("%u", x);
        if((x % 5) == 0) puts("");
        else printf("\t");
    }
}