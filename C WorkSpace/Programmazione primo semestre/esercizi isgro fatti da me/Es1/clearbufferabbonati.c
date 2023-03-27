#include<stdio.h>
#define PSCO        0.10
#define SSCO        0.15 
#define DSCO        0.25

void clearBuffer(void)
{
	char c;
	
	while( (c = getchar()) != '\n' && c != EOF);  //utile per evitare errori con getchar con scan multipli
}

int main()
{
    double costo, sconto;
    int c;
    char categoria;

    printf("Inserire costo biglietto\n");
    scanf("%lf", &costo);
    clearBuffer();          //serve per non far leggere la premuta Invio come char da dare a categoria
    printf("Inserire categoria P, S o D\n");
    scanf("%c", &categoria);
    

        switch (categoria)
        {
        case 'P': sconto=PSCO;
            break;
        case 'S': sconto=SSCO;
            break;
        case 'D': sconto=DSCO;
            break;
        default: puts("Nessuno Sconto");
            break;
        }
        costo -= costo*sconto;

        printf("Costo %.2lf", costo);
}