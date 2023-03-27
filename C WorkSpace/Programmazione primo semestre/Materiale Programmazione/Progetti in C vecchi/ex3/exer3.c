#include <stdio.h>
#define IMPMIN 100
#define IMPMAX 300
#define SCOMIN 0.05
#define SCOMAX 0.10

int main(void)
{
float prezzo;

printf("inserisci prezzo prodotto\n");
scanf("%f",&prezzo);

if(prezzo>=IMPMAX){
prezzo=(1-SCOMAX)*prezzo;
}
else if(prezzo>=IMPMIN){
prezzo=prezzo*(1-SCOMIN);
}
else{
prezzo=0;
}

printf("Prezzo %.2f\n", prezzo);

return 0;
}
