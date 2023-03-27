#include<stdio.h>

int main()
{
    int x, pri, sec, qua, qui;
    int i = 5, j = 1;

    printf("Inserisci numero --> ");
    scanf("%d", &x);

    pri = x / 10000;
    x %= 10000;
    sec = x / 1000;
    x %= 100; //salto la terza
    qua = x / 10;
    x %= 10;
    qui = x;
    
    if(pri == qui && sec == qua) printf("Palindromo");
    else printf("Non e' palindromo");

    return 0;

}