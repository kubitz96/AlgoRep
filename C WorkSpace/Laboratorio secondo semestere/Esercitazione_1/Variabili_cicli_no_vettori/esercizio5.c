//stampare i numeri da 1 a 50 separati da uno spazio e andando a capo ogni 10

#include<stdio.h>

int main()
{
	int x = 1;

	while(x < 51)
	{
		printf("%3d", x);
		if (x % 10 == 0) printf("\n");
		++x;
	}

	return 0;
}