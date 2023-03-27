#include<stdio.h>

unsigned long long int factorial(unsigned int number);

int main()
{
    unsigned int x;

    printf("Inserire Numero Intero Positivo\n");
    scanf("%u", &x);

    
    printf("%u! = %11u", x, factorial(x));
}

unsigned long long int factorial(unsigned int number){
    if(number <= 1){
        number= 1;
        return number;
    }else return number*(factorial(number - 1)); //non viene ripetuto lo stesso ciclo piu volte come un for,
                                                //in realtà si crea un effetto matriosca della funzione per arrivare al caso base.

}