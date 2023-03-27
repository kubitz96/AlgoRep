#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void modify(int *p, int n);
void print(int *p, int n);

int main()
{
    int *p;
    
    p = (int*)calloc(5,sizeof(int));

    print(p,5);

    modify(p,5);

    print(p,5);

}

void modify(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i]= 5;
    }
}

void print(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%d", p[i]);
    }
    
}