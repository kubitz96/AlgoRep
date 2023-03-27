#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c, delta ;
    float x1, x2 ;

    printf("Inserire coefficienti equazione\nSecondo Grado --> ") ;
    scanf("%d", &a) ;
    printf("Primo grado --> ") ;
    scanf("%d", &b) ;
    printf("Termine noto --> ") ;
    scanf("%d", &c) ;

    delta= b*b -(4*a*c) ;
     if (delta<0) {
        printf("Non ci sono soluzioni") ;
    }
    
    x1= -b + sqrt(delta) ;

    if (delta==0){
        x2=x1 ;
        printf("Le soluzioni coincidono e sono uguali a %d", x1) ;
    }
    if(delta>0) {
        x2= -b - sqrt(delta) ;
        printf("Le soluzioni sono %f %f", x1, x2) ;
    }

   return 0 ;

}