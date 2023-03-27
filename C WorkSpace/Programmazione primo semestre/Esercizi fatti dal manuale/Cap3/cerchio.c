#include<stdio.h>
#define PI 3.14159

int main()
{
    float r;

    puts("Inserisci Raggio");
    scanf("%f", &r);

    printf("Diametro %f\nCirconferenza %f\nArea %f", 2*r, 2*r*PI, r*r*PI);
}