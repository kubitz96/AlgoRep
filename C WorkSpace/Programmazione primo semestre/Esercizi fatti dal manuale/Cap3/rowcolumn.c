#include<stdio.h>

int main()
{
    unsigned int row = 10;

    while(row >= 1){ //scorre righe
        unsigned int column = 1;
        while(column <= 10){ //scorre colonne
            printf("%s", row % 2 ? "<" : ">");
            ++column;
        }
        --row;
        puts("");
    }
}