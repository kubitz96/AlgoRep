#include<stdio.h>

int main()
{
    int b = 3;
    int *a = &b;


    printf("address:\n%p\n%p\n", a, &b);
    printf("value:\n%d\n%d", *a, *&b);
}
