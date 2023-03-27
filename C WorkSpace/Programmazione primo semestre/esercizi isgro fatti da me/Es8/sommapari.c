#include<stdio.h>

int sommaPari(int n);

int main()
{
    int C;

    puts("Inserire numero Intero");
    scanf("%d", &C);

    printf("Somma dei numeri pari fino all'intero scelto = %d", sommaPari(C));
}

/*int sommaPari(int n)   //questo va bene se inserisco la quantita di numeri pari da sommare a partire dal primo
{
    if(n == 0) return 0;
    return 2*n + (sommaPari(n-1));
}*/ 

int sommaPari(int n)
{
    int sum = 0;
    if(n % 2 == 0 && n == 2) return 2;
    if(n % 2 != 0) --n;

    sum = n + sommaPari(n-2);

    //return sum;   non capisco perchè è superfluo (forse perche in automatico mi ritorna n decrementato)

}