#include<stdio.h>

int main()
{
    int i, x, max, exmax;
    exmax=max=0; // max va inizializzato poiche quando si fa il primo confronto non confronta con nulla

    for(i = 0; scanf("%d", &x) == 1 ; ++i){
        
        if(x > max) {
            exmax= max;
            max = x;
        }
    }
    printf ("MAX %d %d", exmax, max);
}
