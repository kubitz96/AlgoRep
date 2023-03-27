#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char c;

    fp = fopen("fileditesto.txt", "r");

    if(fp == NULL)
    {
        fprintf(stderr, "Errore!\n"); //perror("Errore") e la stessa cosa
        return -1;
    }

    while(fscanf(fp,"%c", &c) == 1)
    {
        //fscanf(fp,"%c", &c); sconsigliato
        //con while 1 if(feof(fp)) break;
        printf("%c", c);
    }
    fclose(fp);

    return   0;
}