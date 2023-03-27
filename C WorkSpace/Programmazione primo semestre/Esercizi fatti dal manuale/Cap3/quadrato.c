#include<stdio.h>

int main()
{
    int lato, i, j;

    printf("Inserire Lato quadrato --> ");
    scanf("%d", &lato);

    for(i = 1; i <= lato; ++i){
        for(j =1; j <= lato; ++j) {
            if(i == 1 || i == lato) printf("*");    //only printf("*") per quadrato pieno
                else if(j > 1 && j < lato) printf(" ");   //3 casi diversi per la stessa cella quindi 2 else
                    else printf("*");
        }
        puts("");
    }
    return 0;
}