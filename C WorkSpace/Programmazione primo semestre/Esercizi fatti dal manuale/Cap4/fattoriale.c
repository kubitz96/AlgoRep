#include<stdio.h>

int main()
{
    unsigned int x, fat = 1, i, j;
    puts("X\tFattoriale");

    for(i = 1; i <= 5; ++i){
        fat *= i; 
        printf("%u\t%u\n", i, fat);
    }
    puts("");


    puts("X\tFactorial of X"); // stampa le intestazioni di tabella
// calcola il fattoriale degli interi da 1 a 5
for (unsigned int i = 1; i <= 5; ++i) {
unsigned int factorial = 1;
// calcola il fattoriale del numero corrente
for (unsigned int j = 1; j <= i; ++j) {
factorial *= j;
}
printf("%u\t%u\n", i, factorial);
}
}