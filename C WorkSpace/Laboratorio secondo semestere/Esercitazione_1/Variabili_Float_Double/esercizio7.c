/*date le coordinate P 1 = (x 1 , y 1 ) e P 2 = (x 2 , y 2 ) di due punti, fare un programma che ne calcoli
la distanza euclidea (si ricorda che la distanza euclidea tra due punti è pari a d(P 1 , P 2 ) =
[√(x 1 − x 2 )² + (y 1 − y 2 )²].
Ricorda: se si usano formula matematiche in fase di compilazione aggiungere -lm per linkare
la libreria per le funzioni dichiarate in math.h*/

#include<stdio.h>
#include<math.h>

int main()
{
	double x1, x2, y1, y2;	//la funzione sqrt ritorna un double

	printf("Inserire coordinate P1\n");
	scanf("%lf%lf", &x1, &y1);

	printf("Inserire coordinate P2\n");
	scanf("%lf%lf", &x2, &y2);

	printf("La distanza euclidea tra i due punti e' %.2lf\n", sqrt((pow(x1-x2,2)+pow(y1-y2,2))));

	return 0;

}