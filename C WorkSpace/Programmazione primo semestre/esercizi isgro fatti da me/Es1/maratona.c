#include<stdio.h>

int main()
{
    float miles, yards, km ; //mile=1760 yards, mile=1.609 km

    printf("Miglia --> ") ;
    scanf("%f", &miles) ;
    printf("Iarde --> ") ;
    scanf("%f", &yards) ;

    // 1 miles : 1760 yards = x miles : tot yards --- conversione iarde miglia è totyards/1760
    // 1 miles : 1.609km = totmiles : x km --- conversione miglia kilometri  miles*1.609

    miles=miles+(yards/1760) ;
    km= miles*1.609 ;

    printf("Kilometri --> %f", km) ;

    return 0 ;

}