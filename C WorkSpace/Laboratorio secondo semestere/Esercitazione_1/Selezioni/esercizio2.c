/*fare un programa che, dati in input 3 valori a,b ed x, stampi se x è compreso tra a e b o meno
(estremi inclusi)*/

#include<stdio.h>

int main()
{
	float a, b, x;

	printf("Inserire estremi a, b e un valore x\n");
	scanf("%f%f%f", &a, &b, &x);

	if((x >= a && x <= b) || (x >= b && x <= a)) printf("COMPRESO\n");
	else printf("NON COMPRESO\n");

	return 0;
}