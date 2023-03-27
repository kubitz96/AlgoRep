#include<stdio.h>

#define     SIZE  10

int main()
{
    double fractions[SIZE] = {0};

    //array[4];
    fractions[9] = 1.667;
    fractions[3] = 3.333;

    printf("%.2lf %.2lf", fractions[6], fractions[9]);

    for (size_t x = 0; x < SIZE; ++x)
    {
        printf("%.2lf ", fractions[x]);
    }
    
}