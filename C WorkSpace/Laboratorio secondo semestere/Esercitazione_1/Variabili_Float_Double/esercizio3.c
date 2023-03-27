//dato il raggio da input, fare un programma che calcoli e stampi area e perimetro di un cerchio

#include<stdio.h>

#define PIGRECO 3.14

int main()
{
	float raggio;

	printf("Inserire raggio\n");
	scanf("%f", &raggio);

	printf("L'area del cerchio e' %.2f\n", raggio*raggio*PIGRECO);
	printf("La circonferenza del cerchio e' %.2f\n", 2*PIGRECO*raggio);

	return 0;
}