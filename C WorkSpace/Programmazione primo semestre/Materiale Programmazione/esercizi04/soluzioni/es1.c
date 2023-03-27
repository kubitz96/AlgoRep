#include <stdio.h>

#define BANCONOTA_H	50
#define BANCONOTA_L 20

int main()
{
	int cifra;
	int numero_banconote_H, numero_banconote_L;
	
	printf("Quanto vuoi prelevare  ");
	scanf("%d", &cifra);
	
	numero_banconote_H = cifra / BANCONOTA_H;
	cifra = cifra % BANCONOTA_H;
	
	numero_banconote_L = cifra / BANCONOTA_L;
	
	if (numero_banconote_H > 0) {
		printf("banconote da %d : %d \n", BANCONOTA_H, numero_banconote_H);
	}
	if (numero_banconote_L > 0) {
		printf("banconote da %d : %d \n", BANCONOTA_L, numero_banconote_L);
	}
	cifra = numero_banconote_H * BANCONOTA_H + numero_banconote_L * BANCONOTA_L;
	printf("Somma erogata %d \n", cifra);
	
	return 0;
}
