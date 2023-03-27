#include<stdio.h>
#include<stdlib.h>

int trovaquadrante(int x, int y);
void clearBuffer(void);

int main()
{
    int a, b, result;

    printf("Inserisci coordinate (X,Y)\n");

 if((scanf("%d%d", &a, &b)) != 2){                              //caso di errori di input pulire sempre il buffer
     //clearBuffer();
     puts("Errore");
 }else{
    result=trovaquadrante(a, b);

        switch (result){
    case 0: puts("Punto di Origine (0,0)");
        break;
    case 5: printf("Il punto e' sull' asse y nel punto (0,%d)\n", b);
        break;
    case 6: printf("Il punto e' sull' asse x nel punto (%d,0)\n", a);
        break;
    case 1: printf("Il punto e'nel primo quadrante (%d,%d)\n", a, b);
        break;
    case 2: printf("Il punto e'nel secondo quadrante (%d,%d)\n", a, b);
        break;
    case 3: printf("Il punto e'nel terzo quadrante (%d,%d)\n", a, b);
        break;
    case 4: printf("Il punto e'nel quarto quadrante (%d,%d)\n", a, b);
        break;
    
    default: puts("Errore");
                exit(1);
            }
        }
}   



int trovaquadrante(int x, int y){
    int quadrante;

    if(x == y && x == 0) quadrante= 0; //puts("Punto di Origine (0,0)");
    if(x == 0 && y != 0) quadrante= 5; //printf("Il punto è sull' asse y nel punto (0,%d)", y);
    if(y == 0 && x != 0) quadrante= 6; //printf("Il punto è sull' asse x nel punto (%d,0)", x);
    if(x > 0 && y > 0) quadrante= 1;
    if(x < 0 && y > 0) quadrante= 2;
    if(x < 0 && y < 0) quadrante= 3;
    if(x > 0 && y < 0) quadrante= 4;

    return quadrante;
}

void clearBuffer(void)
{
	char c;
	
	while( (c = getchar()) != '\n' && c != EOF);  //utile per evitare errori con getchar con scan multipli
}