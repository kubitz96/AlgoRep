#include<stdio.h>

int main()
{
    int x = 1;
    int i = 1;

    while(x <= 64){
        if(x % 8 == 0) {
            puts("");
            ++i;
            if(i % 2 == 0) printf("%s", " ");
        }
        else printf("* ");
        ++x;
    }
}