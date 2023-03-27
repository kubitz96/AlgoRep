#include<stdio.h>
#define PROD1       2.98
#define PROD2       4.50
#define PROD3       9.98
#define PROD4       4.49
#define PROD5       6.87

int main()
{
    int n, quantita;
    double totale = 0;

    printf("Inserire Numero Prodotto\n");
    scanf("%d", &n);
    

    while(n != -1){

        printf("Inserire quantita venduta al giorno\n");
        scanf("%d", &quantita);
        
        switch (n) {
            case 0:
        break;
            case 1: totale += PROD1*quantita;
        break;
            case 2: totale += PROD2*quantita;
        break;
            case 3: totale += PROD3*quantita;
        break;
            case 4: totale += PROD2*quantita;
        break;
            case 5: totale += PROD2*quantita;
        break;
    
            default: puts("errato inserire di nuovo");
        }
        printf("Inserire Numero Prodotto(-1 to end)\n");
        scanf("%d", &n);
    }

    printf("%.2lf", totale);
}