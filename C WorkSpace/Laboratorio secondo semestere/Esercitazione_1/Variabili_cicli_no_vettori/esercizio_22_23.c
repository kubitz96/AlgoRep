/*data una sequenza di 10 numeri, dire se la sequenza inserita è crescente o no (NB: l’output
deve essere prodotto alla fine)*/

#include<stdio.h>

int main()
{
	float x, tmp;
	int flag = 1;

	printf("Inserire sequenza di 10 numeri\n");
	scanf("%f", &tmp);

	for(int i = 1; i < 10; ++i)
	{
		scanf("%f", &x);
		if(flag == 1 && x < tmp) flag = 0;
		tmp = x;
	}

	if(flag) printf("La sequenza e' crescente\n");
	else printf("La sequenza non e' crescente\n");

	return 0;

}