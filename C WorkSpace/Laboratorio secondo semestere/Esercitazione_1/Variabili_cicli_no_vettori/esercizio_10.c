//Inserendo 10 numeri interi, calcola quanti numeri pari sono stati inseriti

#include<stdio.h>

int main()
{
	int x;
	int cnt = 0;

	printf("Inserire 10 numeri interi\n");

	for(int i = 0; i < 10; ++i)
	{
		scanf("%d", &x);

		if(x % 2 == 0) ++cnt;
	}
	
	printf("Numeri pari inseriti : %d\n", cnt);

	return 0;
}	