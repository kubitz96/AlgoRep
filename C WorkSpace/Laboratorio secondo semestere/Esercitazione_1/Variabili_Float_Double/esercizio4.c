//fare un programma che calcoli e stampi la media di 4 numeri interi dati dall’utente

#include<stdio.h>

int main()
{
	float a,b,c,d;

	printf("Inserire 4 numeri interi positivi\n");
	scanf("%f%f%f%f", &a,&b,&c,&d);

	printf("La media e' %.2f\n", (a+b+c+d)/4);

	return 0;
}