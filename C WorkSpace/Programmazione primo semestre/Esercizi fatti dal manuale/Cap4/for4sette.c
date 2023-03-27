#include<stdio.h>

int main()
{   
    int x;

    for(x = 1; x <=7; ++x){
        printf("%d\t", x);
    }
    puts("");

    for(x = 3; x <=23; x += 5){
        printf("%d\t", x);
    }
    puts("");

    for(x = 20; x > -11; x -= 6){
        printf("%d\t", x);
    }
    puts("");

    for(x = 19; x <= 51; x += 8){
        printf("%d\t", x);
    }
    puts("");

    return 0;
}