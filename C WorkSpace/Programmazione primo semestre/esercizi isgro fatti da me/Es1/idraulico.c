#include<stdio.h>
#define PAGAORA  40.00
#define PAGAMIN 100.00

int main()
{
    float materiale, spesa ,costOre;
    int ore ;
    
    printf("Costo Materiale --> ") ;
    scanf("%f", &materiale) ;
    printf("Ore --> ") ;
    scanf("%d", &ore) ;

    costOre= ore*PAGAORA ;
    spesa= costOre+materiale ;

    if(spesa<100) spesa=100 ;

    printf("Prezzo Finale --> %.2f", spesa) ;

    return 0 ;

}