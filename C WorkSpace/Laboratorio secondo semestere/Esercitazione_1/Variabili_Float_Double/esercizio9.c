/*dati i coefficienti in a,b,c in input ed un valore x, risolvere un’equazione di secondo grado
in forma normale (ossia, considerando l’equazione ax²+ bx + c = 0, dati i valori di a, b, c,
calcolare stampare i corrispondenti valori di x)*/

#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c;

	printf("Inserire valori a,b,c\n");
	scanf("%lf%lf%lf", &a, &b, &c);

	double delta = pow(b,2) - 4*a*c;

	if(delta >= 0)
	{
		printf("I valori di x sono: x1 = %.2lf, x2 = %.2lf\n", (sqrt(delta)-b)/(2*a), (-sqrt(delta)-b)/(2*a));
	}
	else printf("Non esiste soluzione\n");

	return 0;
}

