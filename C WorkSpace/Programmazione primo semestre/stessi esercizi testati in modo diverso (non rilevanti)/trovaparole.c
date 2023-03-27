#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int Find_Word(char const *p);

int main()
{
    char *s= "patt mammt sort";

    int parole;

    parole = Find_Word(s);

    printf("Parole trovate %d", parole);
}

int Find_Word(char const *p)
{
    int cnt = 0;

    while (*p != '\0') //scorri finche non finisce la stringa
    {
        if(isspace(*p)) ++p; //salta se è uno spazio
        if(*p != '\0') ++cnt; //trovata parola
        while(!isspace(*p) && *p != '\0') ++p; //scorri parola
    }
    return cnt;
}