#include<stdio.h>

int main()
{
    int x, y;

    scanf("%d%d", &x, &y); //STAMPA X ELEMENTI PER Y RIGHE10
    
    for( int i = 1; i <= y; ++i){
        for(int j = 1; j <= x; ++j) {
            printf("@ ");
        }
        puts("");
    }

}