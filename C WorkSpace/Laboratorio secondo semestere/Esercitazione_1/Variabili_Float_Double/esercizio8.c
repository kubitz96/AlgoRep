/*dati in input i coefficienti m e q ed un valore y, fare un programma che risolva la corrispondente
equazione di primo grado in forma normale (ossia, considerando l’equazione y = mx + q, dati
i valori di m,q ed y, calcolare stampare il valore di x)*/

#include<stdio.h>
#include<math.h>

int main()
{
	float m, q, y;

	printf("Inserire valori m, q e y\n");
	scanf("%f%f%f", &m, &q, &y);

	printf("Il valore di x e' %.2f\n", (y-q)/m);

	return 0;
}