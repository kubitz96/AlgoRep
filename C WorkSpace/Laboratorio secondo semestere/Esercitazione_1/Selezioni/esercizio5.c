/*fare un programa che calcoli e stampi il massimo tra 3 valori dati dall’utente in 3 variabili
distinte*/

#include<stdio.h>

int main()
{
	int a, b, c, max;

	printf("Inserire 3 valori interi\n");
	scanf("%d%d%d", &a, &b, &c);

	max = a;

	if(b > max) max = b;
	if(c > max) max = c;

	printf("Il massimo e' %d\n", max);

	return 0;

}