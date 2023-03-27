#include<stdio.h>

int main()
 {
    int product = 1;
    int count = 11;
    int q, divisore;

    product *= 2;
    product = product * 2;

    if(count > 10) puts("Count e' maggiore di 10");

    q = 10;
    divisore = 2;
    printf("%d\n", q/divisore);
    printf("resto %d\n", q%divisore);
    q /= divisore; //q = q / divisore
    printf("%d", q);


 }