//fare un programma che calcoli e stampi la media pesata di 4 numeri interi e 4 pesi reali dati dall’utente

#include<stdio.h>

int main()
{
	float a,b,c,d;
	float pes_a,pes_b,pes_c,pes_d;

	printf("Inserire 4 numeri interi positivi\n");
	scanf("%f%f%f%f", &a,&b,&c,&d);

	printf("Inserire 4 pesi corrispettivamente ai numeri inseriti\n");
	scanf("%f%f%f%f", &pes_a,&pes_b,&pes_c,&pes_d);

	printf("La media pesata e' %.2f\n", (a*pes_a+b*pes_b+c*pes_c+d*pes_d)/(pes_a+pes_b+pes_c+pes_d));

	//la media pesata si ottiene dalla sommatoria dei valori moltiplicati per il peso corrispondente e dividere tutto per la somma dei pesi 

	return 0;
}