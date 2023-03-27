/*fare un programa che, dato da tastiera un numero reale, ne calcoli e ne stampi il valore
assoluto*/

#include<stdio.h>
#include<math.h>

int main()
{
	double x;

	printf("Inserire numero reale\n");
	scanf("%lf", &x);

	printf("Valore assoluto = %.2lf\n", fabs(x));

	return 0;
}