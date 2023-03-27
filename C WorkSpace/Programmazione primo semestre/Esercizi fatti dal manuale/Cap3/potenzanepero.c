#include<stdio.h>

int main()
{
    float x, y, z, i; 
    float fattoriale = 1;
    x = 1;
    printf("Inserire grado di e ");
    scanf("%f", &y);
    z = y;
    printf("e elevato a %.0f", z);

    for(i = 1; i <= y; ++i){
        fattoriale *= i;
        x += z/fattoriale;
        z *= z;
        
    }
    printf(" vale circa %.2f", x);
    
}