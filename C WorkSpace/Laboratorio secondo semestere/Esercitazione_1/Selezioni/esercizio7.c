/*dati da tastiera 3 valori a,b e op, stampare:
la somma di a e b se op è 1;
la differenza tra a e b se op è 2;
il prodotto tra a e b se op è 3;
il quoziente tra a e b se op è 4.*/

#include<stdio.h>

int main()
{
	float a, b;
	int op;

	printf("Inserire due numeri e numero di operazione corrispondente\n");
	scanf("%f%f%d", &a, &b, &op);

	switch(op)
	 {
	 	case 1 : printf("La somma e' %.2f\n", a+b);
	 	break;

	 	case 2 : printf("La differenza e' %.2f\n", a-b);
	 	break;

	 	case 3 : printf("Il prodotto e' %.2f\n", a*b);
	 	break;

	 	case 4 : printf("Il quoziente e' %.2f\n", a/b);
	 	break;

	 	default: printf("Operazione errata");
	 	break;
	 }

	 return 0;
}