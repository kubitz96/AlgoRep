#include <stdio.h>


void leggi_parametri(int *x, int *y)
{
	printf("Inserisci 2 coordinate intere --> ");
	while (scanf("%d%d", x, y) != 2) {
		printf("Valori errati\n");
		printf("Inserisci 2 coordinate intere --> ");
	}
}


int quadrante4(int x, int y)
{
	if (x > 0 && y < 0) return 1;
	return 0;
	
	//return (x > 0 && y < 0);
}

int quadrante3(int x, int y)
{
	if (x < 0 && y < 0) return 1;
	return 0;
	
	//return (x < 0 && y < 0);
}

int quadrante2(int x, int y)
{
	if (x < 0 && y > 0) return 1;
	return 0;
	
	//return (x < 0 && y > 0);
}


int quadrante1(int x, int y)
{
	if (x> 0 && y > 0) return 1;
	return 0;
	
	//return (x> 0 && y > 0);
}


int asseY(int x, int y)
{
	if (x==0 && y!=0) return 1;
	return 0;
	
	//return (x==0 && y!=0);
}

int asseX(int x, int y)
{
	if (y==0 && x != 0) return 1;
	return 0;
	
	//return (y==0 && x!=0);
}

int origine(int x, int y)
{
	if (x == 0 && y == 0) {
		return 1;
	}
	
	return 0;
	
	
	//return (x == 0 && y == 0);
}

int main()
{
	int x, y;
	
	leggi_parametri(&x, &y);
	
	if (origine(x,y)) {
		printf("Punto origine\n");
	}
	else {
		if (asseX(x,y)) {
			printf("Asse X\n");
		}
		else {
			if (asseY(x,y)) {
				printf("Asse Y\n");
			}
			else {
				if (quadrante1(x,y)) {
					printf("Primo quadrante\n");
				}
				else {
					if (quadrante2(x,y)) {
						printf("Secondo quadrante\n");
					}
					else {
						if (quadrante3(x,y)) {
							printf("Terzo quadrante\n");
						}
						else {
								printf("Quarto quadrante\n");
						}
					}
				}
			}
		}
	}
	
	return 0;
}
