#include<stdio.h>

int main()
{
    int x = 1;

    while (x <= 100){
        /*if()*/x % 10 == 0 ? printf("%s", "*\n") : printf("%s", "*");
        //else if(x % 1 == 0) printf("%s", "*");
        ++x;
    }
    return 0;
}