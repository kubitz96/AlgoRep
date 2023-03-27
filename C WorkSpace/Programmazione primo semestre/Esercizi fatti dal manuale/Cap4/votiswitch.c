#include<stdio.h>

int main()
{
    unsigned int acnt = 0;
    unsigned int bcnt = 0;
    unsigned int ccnt = 0;
    unsigned int dcnt = 0;
    unsigned int ecnt = 0;
    unsigned int fcnt = 0;

    int voto;

    printf("Inserire Voto(EOF per terminare)\n");

    while((voto = getchar()) != EOF){ // getchar legge caratteri EOF = -1 (valore) dipende dal sistema
                                      //per inserire il tasto EOF su windows ctrl+z su altri ctrl+d
        switch(voto) { //variabile a cui assegnare diversi casi
        case 'A':
        case 'a':
        ++acnt;
        break;

        case 'B':
        case 'b':
        ++bcnt;
        break;

        case 'C':
        case 'c':
        ++ccnt;
        break;

        case 'D':
        case 'd':
        ++dcnt;
        break;

        case 'E':
        case 'e':
        ++ecnt;
        break;

        case 'F':
        case 'f':
        ++fcnt;
        break;

        case '\n':  //ricordarsi di elaborare spazio newline e tabulazioni quando si leggono i caratteri
        case '\t':
        case ' ':
        break;

        default:
        printf("%s", "voto errato\n");
        puts("Inserire Nuovo voto");
        // break; facoltativo
        } //fine switch

     
    }  //fine while

    printf("A: %u\n", acnt); 
    printf("B: %u\n", bcnt); 
    printf("C: %u\n", ccnt); 
    printf("D: %u\n", dcnt); 
    printf("E: %u\n", ecnt); 
    printf("F: %u\n", fcnt);

    return 0;
}