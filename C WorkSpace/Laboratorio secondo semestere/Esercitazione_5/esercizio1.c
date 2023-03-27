/*Fornire una semplice implementazione di un gioco simile al black jack avente come sfidante il computer.

L'utente potrà scegliere ripetutamente tra due possibilità:

estrarre una carta
fermarsi
nello specifico:

Estrarre una carta
L'estrazione di una carta comporta la produzione di un numero casuale con valore che può andare da 1 a 13. Ad ogni estrazione,
 tale valore andrà sommato ai valori ottenuti fino a quel momento. La somma di tali valori sarà il punteggio 
dell'utente. Se, durante le diverse estrazioni, supera il valore 21, la partita termina automaticamente con messaggio per l'utente "hai perso!".

Fermarsi
Tenendo come riferimento il punteggio ottenuto dall'utente, la macchina dovrà provare a battere tale punteggio producendo un punteggio. 
La macchina continuerà ad estrarre numeri casuali (tra 1 e 13) finchè il suo punteggio  non supera . Se tale punteggio 
però supera 21 allora la macchina avrà perso, producendo come messaggio all'utente "hai vinto!". Se invece la macchina riesce ad ottenere un punteggio 
maggiore o uguale al punteggio dell'utente la macchina avrà vinto, ed il messaggio per l'utente sarà "hai perso!".*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pesca();

#define PMAX 21

int main()
{
    int scelta = 0;
    int punt_u = 0;

    printf("Turno dell'utente\n");

    while(scelta != 2)
    {
        printf("Punteggio attuale %d.\n", punt_u);
        printf("Scegli:\n1) Estrai una carta\n2) Fermati\n");
        scanf("%d", &scelta);
        if(scelta == 1) punt_u += pesca();
        else if(scelta != 2) printf("Scelta non valida, ripeti!\n"); 
        if (punt_u > PMAX) scelta = 2;
    }

    if (punt_u > PMAX) printf("Hai Perso!");

    else
    {
    int punt_m = 0;
    printf("Hai terminato il turno!\nTurno della macchina\n");
     while(punt_m < punt_u)
     {
        printf("Punteggio attuale %d.\n", punt_m);
        punt_m += pesca();
        if(punt_m > PMAX) printf("Hai vinto!\n");
        else if(punt_m >= punt_u) printf("La macchina ha vinto!\n");
     }
    }

    return 0;
}

int pesca()
{
    int carta;

    srand(time(NULL));

    carta = 1 + rand() % 13;

    printf("Carta pescata: %d.\n", carta);  //return rand() % (b + 1 - a) + a; metodo se si vuole definire un intervallo tra il minimo a e il massimo b;

    return carta;
}