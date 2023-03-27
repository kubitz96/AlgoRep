#include<stdio.h>

int main()
{
    int riga, aste, spazi;

    for(riga = 1; riga <= 9; riga += 2){ //stampa righe
        for(spazi = (9-riga)/2; spazi > 0; --spazi){
            printf(" "); //stampa primi spazi
        }
        for(aste = 1; aste <= riga; ++aste){ //stampa asterischi
                printf("*");           
        }
        
        puts("");
    }
    for(riga = 7; riga > 0; riga -= 2){
        for(spazi = (9 - riga)/2; spazi > 0; --spazi) printf(" ");
        for(aste = 1; aste <= riga; ++aste) printf("*");
        puts("");
    }
}