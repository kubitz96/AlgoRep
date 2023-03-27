#include <stdio.h>

int main(void)
{
	int a, b;
	int max, min;

	printf("inserisci due interi\n");
	printf("primo intero-->\n");
	scanf("%d", &a);
	printf("secondo intero-->\n");
	scanf("%d", &b);

	if (a==b) {
		printf("i due numeri sono uguali\n");}
	if (a>b)  {
		printf("%d maggiore di %d\n", a, b);}
	if (a<b)  {
		printf("%d minore di %d\n", a, b);}
	return 0;
		 }
		
