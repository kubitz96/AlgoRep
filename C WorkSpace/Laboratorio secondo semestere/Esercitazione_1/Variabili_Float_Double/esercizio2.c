//date base e altezza da input, fare un programma che calcoli e stampi l’area di un triangolo

#include<stdio.h>

int main()
{
	float base, altezza;

	printf("Inserisci Base\n");
	scanf("%f", &base);

	printf("Inserisci Altezza\n");
	scanf("%f", &altezza);

	printf("L'area del triangolo e' %.2f.\n", base*altezza/2);
	
	return 0;
}