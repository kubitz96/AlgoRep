#include<stdio.h>

int integerPower(int base, int exponent);

int main(){
    int x, y;

    printf("Inserire base ed esponente\n");
    scanf("%d%d", &x, &y);

    printf("La potenza vale %d", integerPower(x, y));

    return 0;
}

int integerPower(int base, int exponent){
    int i, totale;

    for(i = 1; i <= exponent; ++i){
        if( i== 1) totale= base;
        else totale *= base;
    }

    return totale;
}