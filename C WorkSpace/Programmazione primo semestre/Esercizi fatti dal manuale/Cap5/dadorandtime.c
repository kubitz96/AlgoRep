#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
    int i, seed;
    
    /*printf("Enter Seed\n");
    scanf("%d", &seed);

    srand(seed);*/ //s rand modifica il seme di rand
    srand(time(NULL)); 

    for(i = 1; i <= 20; ++i){
        printf("%10d", 1+rand() % 6); // rand() % 6 prende solo i numeri da 0 a 5 n= a + rand()%b dove a primo numero b fattore di scala o ampiezza
        if(i % 5 == 0) puts("");
    }
}