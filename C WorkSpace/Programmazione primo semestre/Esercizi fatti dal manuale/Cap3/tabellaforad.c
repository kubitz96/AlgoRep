#include<stdio.h>

int main()
{
    int a = 3, i;
    printf("A\tA+2\tA+4\tA+6\n\n");

    for(i=0; i <5;++i){
        printf("%d\t%d\t%d\t%d\t\n", a, a+2, a+4, a+6);
        a += 3; //se scrivo a+3 non viene visto come un incremento
    }
}