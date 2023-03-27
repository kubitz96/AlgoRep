/*fare un programa che, dato un voto di esame da tastiera, stampi promosso se maggiore o
uguale di 18, bocciato in caso contrario*/

#include<stdio.h>

int main()
{
	int x;

	printf("Inserire Voto da 1 a 30\n");
	scanf("%d", &x);

	if(x < 18) printf("bocciato\n");
	else printf("promosso\n");

	return 0;
}