#include <stdio.h>

int Massimo(int x, int y, int z);  //protoripo di funzione con parametri interi e che ritorna un intero

int main(){

    int num1, num2, num3;            //Valori da confrontare

    printf("\nInserisci i tre valori di cui fare il max(intervallati da uno spazio): ");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("\nIl massimo è:  %d\n\n",Massimo(num1, num2, num3));

    return 0;
}

//Dichiarazione della funzione Massimo definita dal programmatore

int Massimo(int x, int y, int z){

    int max = x;

    if(x<y){
        max = y;
    }

    if(x<z){
        max = z;
    }

    if(y<z){
        max = z;
    }

    return max;
}