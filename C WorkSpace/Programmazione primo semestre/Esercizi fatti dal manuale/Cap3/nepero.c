#include<stdio.h>

int main()
{
    float x, i; 
    float fattoriale = 1;
    x = 1;

    for(i = 1; i < 1000000; ++i){
        fattoriale *= i;
        x += 1/fattoriale;
        
    }
    printf("la costante e vale circa %f",x);
    
}