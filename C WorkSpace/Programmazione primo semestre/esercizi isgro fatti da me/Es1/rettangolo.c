#include<stdio.h>

int main(){
    int base, altezza;

    printf("Base --> ") ;
    scanf("%d", &base) ;
    printf("Altezza --> ") ;
    scanf("%d", &altezza) ;

    printf("Perimetro --> %d\n", (base+altezza)*2) ;
    printf("Area --> %d\n", base*altezza) ;
    
    return 0 ;
}