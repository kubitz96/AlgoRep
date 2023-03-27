#include<stdio.h>

int ismultiple(int primo, int secondo);

int main()
{
    int x, y;
    printf("Inserire due interi per verificare se il secondo e' multiplo del primo\n");
    scanf("%d%d", &x, &y);

    if(ismultiple(x,y) == 0) printf("%d e' multiplo di %d", x, y);
    else if(ismultiple(x,y) == 1) printf("%d e' multiplo di %d", y, x);
    else puts ("Non ci sono multipli");
}

int ismultiple(int primo, int secondo){
    if( primo % secondo == 0) return 0;
    else if(secondo % primo == 0) return 1;
    else return 2;
}