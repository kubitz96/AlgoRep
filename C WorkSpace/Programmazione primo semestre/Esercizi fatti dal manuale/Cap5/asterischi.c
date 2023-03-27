#include<stdio.h>

void quadratoAsterischi(int lato, char carattere);

int main()
{
    int n;
    char c;

    puts("Inserire lunghezza lato quadrato e carattere");
    scanf("%d%c", &n, &c);

    quadratoAsterischi(n, c);
    return 0;
}

void quadratoAsterischi(int lato, char carattere){
    int i, j;

    for(i = 1; i <= lato; ++i){
        for(j = 1; j <= lato; ++j) printf("%c", carattere);
        puts("");
    }
}