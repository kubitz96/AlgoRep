#include<stdio.h>
#include<stdlib.h>

int giornimese(int mese, int anno); // prototipo

int main()
{
    int x, y, z;// x variabile per i mesi e y variabile per i giorni, z variabile anno

    printf("Mese--> ");

    while((scanf("%d", &x)) != -1){
        printf("Anno--> ");
        scanf("%d", &z);                     //diverso da EOF che vale -1
        y= giornimese(x, z); //se questa funzione ritorna un valore io lo devo assegnare ad una variabile
    if(y !=-1) printf("Il mese %d ha %d giorni\n", x, y);
    }

    return 0;
}


int giornimese(int mese, int anno){

    int giorni;         //le variabili dichiarate all interno della funzione fuori dalla funzione svaniscono, rimane solo il valore ritornato (di giorni in questo caso)

        if(anno % 400 == 0) anno= 2; //2 significa non bisestile
        else if(anno % 4 == 0 /*|| anno % 100 == 0 facoltativo perche 100 e multiplo di 4*/) anno= 1; // 1 = anno bisestile
        else anno= 2;
    
    if(mese < 1 || mese > 12){
        puts("errore");
        exit(1);
        giorni= -1;
        return giorni;
    }
    switch (mese)
    {
    case 2: 
            if(anno == 2)giorni= 28;
            else giorni= 29;
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