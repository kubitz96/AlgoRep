#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quozienteIntero(int a, int b);
int restoIntero(int a, int b);

int main()
{
    int x, n;

    printf("Inserisci quante cifre ha il numero e il numero stesso\n");
    scanf("%d%d", &n, &x);

   while( n > 0){
       printf("%3d", quozienteIntero(x,pow(10,n-1)));
       x= restoIntero(x,pow(10,n-1));
       --n;
   }


}

int quozienteIntero(int a, int b){
    return a / b;
}

int restoIntero(int a, int b){
    return a % b;
}