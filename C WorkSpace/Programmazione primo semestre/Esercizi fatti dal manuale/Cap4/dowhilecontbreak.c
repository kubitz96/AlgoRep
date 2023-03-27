#include<stdio.h>

int main()
{
    unsigned int x = 0;

    do{
        ++x;
        //if(x == 5) continue; causa salto altre instuzioni del ciclo in quel singolo step del ciclo 
        printf("%u\n", x);
        //if(x == 5) break; causa uscita dal ciclo
    }
    while(x < 10);
}