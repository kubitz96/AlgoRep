#include<stdio.h>

int even(int numero);

int main()
{
    int x;
    printf("Inserire numero \n");

    while(scanf("%d", &x) == 1){
    if(even(x)) printf("e' pari\n"); //true
    else printf("e' dispari\n");    //false
    printf("Inserire numero\n");
    }
}

int even(int numero){

    return !(numero % 2); //se il resto è 0 allora l'opposto è 1 (true)


    /*if( numero % 2 == 0) return 1;
    else return 0;*/
}