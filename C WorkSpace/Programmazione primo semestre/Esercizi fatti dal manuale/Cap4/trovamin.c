#include<stdio.h>
#include<limits.h>

int main()
{
    int x, min = INT_MAX;
    unsigned int n;

    puts("Quanti Interi");
    scanf("%u", &n);
    puts("Interi");

    while(n > 0){
        
        scanf("%d", &x);
        if(x < min) min = x;
        --n;
    }
    printf("Il minimo e' %d", min);
}