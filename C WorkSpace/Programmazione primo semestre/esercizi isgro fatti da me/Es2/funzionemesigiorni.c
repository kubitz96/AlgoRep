#include<stdio.h>
#include<stdlib.h>

int giornimese(int mese); // prototipo

int main()
{
    int x, y;// x variabile per i mesi e y variabile per i giorni

    printf("Inserire Numero Mese\n");

    while((scanf("%d", &x)) != -1){ //diverso da EOF che vale -1
        y= giornimese(x); //se questa funzione ritorna un valore io lo devo assegnare ad una variabile
    if(y !=-1) printf("Giorni %d\n", y);
    }

    return 0;
}


int giornimese(int mese){

    int giorni;         //le variabili dichiarate all interno della funzione fuori dalla funzione svaniscono, rimane solo il valore ritornato (di giorni in questo caso)

    if(mese < 1 || mese > 12){
        puts("errore");
        exit(1);
        giorni= -1;
        return giorni;
    }
    switch (mese)
    {
    case 2: giorni= 28;
        break;

    case 4:
    case 6:
    case 9:
    case 11: giorni= 30;
        break;

    default: giorni= 31;
    }
    return giorni;
}