#include<stdio.h>
                                            //codice paga 1=manager, 2=lavoratori, 3=provvigione, 4=cottimo switch
                                            //manager fisso, lavoratori prime 40 ore fisso, 1.5 all'ora di straordinario, lavoratori provvigione 250 + 5.7% di vendite lorde,
                                            //cottimo pagamento fisso*prodotto

int main()
{
    int codice, ore;
    double paga, pagora = 8;

    printf("Inserire Codice Paga(ctrl+z to end)\n");
    while((scanf("%d", &codice) != EOF)){

    switch (codice)
    {
    case 1:
            printf("Paga fissa settimanale di 1000.00$\n");
        break;

    case 2: printf("Inserire ore di lavoro\n");
            scanf("%d", &ore);
            if(ore <=40) paga= pagora*ore;
            else paga= (pagora*40)+(pagora*(ore-40)*1.5);
            printf("Paga totale = %.2lf$\n", paga);
        break;

    case 3: printf("Inserire Vendite Totali\n");
            scanf("%lf", &paga);
            paga= (paga*0.057)+250;
            printf("Paga totale = %.2lf$\n", paga);
        break;
    
    case 4: printf("Inserire articoli prodotti\n");
            scanf("%d", &ore);
            paga= ore*pagora; //supponendo che pagora e lo stesso prezzo per ogni articolo venduto
            printf("Paga totale = %.2lf$\n", paga);
        break;

    default: puts("Codice errato, inserire di nuovo");
             scanf("%d", &codice);
        break;
    }
    }
}