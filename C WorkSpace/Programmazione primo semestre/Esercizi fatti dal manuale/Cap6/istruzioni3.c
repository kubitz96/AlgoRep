#include<stdio.h>

int main()
{
    char f[] = "amerigo";

    printf("%c\n", f[6]);

    float b[5] = {0};

    b[4]= 2.34;

    printf("%.2f\n", b[4]);

    int g[5];

    for (size_t i = 0; i < 5; ++i)
    {
        g[i] = 8;
    }

    int total = 0;
    int c[100];
    for (size_t i = 0; i < 100; ++i)
    {
        total += c[i];
    }
    
    double a[11], b[34];

    for (size_t i = 0; i < 11; ++i)
    {
        b[i]= a[i];
    }
    
}