#include<stdio.h>       //interesse = principal*rate*days/365

int main()
{
    float loan, rate, interest;
    unsigned int days;

    printf("Inserire Prestito\n$");
    scanf("%f", &loan);

    while(loan != -1){
        printf("Inserire tasso di interesse\n");
        scanf("%f", &rate);
        printf("Inserire totale giorni del prestito\n");
        scanf("%u", &days);
        printf("Interesse = $%.2f\n\n", loan*rate*days/365);
        printf("Inserire Prestito\n$");
        scanf("%f", &loan);
    }

}