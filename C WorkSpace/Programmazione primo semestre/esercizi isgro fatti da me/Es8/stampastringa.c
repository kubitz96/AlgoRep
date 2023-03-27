#include<stdio.h>

void printStr(char *p);
void readFile(const char *filename);


int main()
{
    FILE *fp;
    char vect[200];

    fp = fopen("stringa.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Errore!\n");
    }
    for (size_t i = 0; i < 200; i++)
    {
      
    }
    

    printStr(fp);
}

void printStr(char *p)
{
    if(*p != '\0') //*p e come scrivere p[0]
    {
    putchar(*p);
    printStr(p+1);
    }
}
