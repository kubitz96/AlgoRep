#include<stdio.h>

int main()
{
    float lordi, dollari;
    printf("Inserire vendite in dollari \n$");
    scanf("%f", &lordi);

    while(lordi != -1){   
        dollari = lordi*0.09 + 200;
        printf("Salario $%.2f\n", dollari);
        printf("Inserire vendite in dollari \n");
        scanf("%f", &lordi);
    }
}