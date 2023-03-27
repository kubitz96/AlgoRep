#include<stdio.h>
#include<stdlib.h>

int main()
{
    int result, i ;
    int psd, fld ;

    psd=fld=0 ;

    for(i=0 ; i<=10; ++i){
        printf("Inserire Risultato --> ") ;
        scanf("%d", &result);
        if(result !=2 && result !=1) {                  //condizione di errore metterla sempre prima di tutti
            printf("Inserire numero corretto --> ") ;
            scanf("%d", &result) ;
        }
       
            if(result == 1) ++psd ;
            else if(result == 2)++fld ;
    }
    printf("\n\nSuperati --> %d\nFalliti --> %d\n", psd, fld) ;
    if(psd >= 8) puts("Bonus Istruttore") ;
}