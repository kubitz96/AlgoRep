#include<stdio.h>
//una classe di 10 studenti fa un quiz, avete a disposizione i voti(interi da 0 a 100). fare la media dei voti.
int main()
{   
    int voto, somma ;
    int media ;
    int cnt = 0 ; //iterazione controllata da contatore , iterazione definita.
    somma = 0 ;

    while(cnt < 10){
    puts("Inserisci Voto") ;
    scanf("%d", &voto) ;
    somma += voto ;
    ++cnt ;
    }

    media= somma/10 ;

    printf("Media %d", media) ;
}