#include<stdio.h>

int main()
{
    int numero;
    double oldlimit, newlimit, saldo;

    printf("Inserire Numero Conto Cliente\n");

    while(scanf("%d", &numero) != EOF){
        printf("Inserire Limite Credito Vecchio\n");
        scanf("%lf", &oldlimit);
    newlimit= oldlimit/2;
        printf("Il nuovo limite e' %.2lf\n", newlimit);
        printf("Inserire Attuale Saldo di credito\n");
        scanf("%lf", &saldo);
    saldo > newlimit ? puts("Limite superato\n") : puts("Il saldo e' accettabile\n");
        printf("Inserire Numero Conto Cliente\n");
    }

    return 0;

}