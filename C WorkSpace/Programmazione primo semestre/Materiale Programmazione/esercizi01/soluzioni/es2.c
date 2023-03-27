#include <stdio.h>

int main()
{
	int a, b;
	int max, min;
	
	printf("Inserisci due interi\n");
	printf("primo intero --> ");
	scanf("%d",&a);
	printf("secondo intero --> ");
	scanf("%d",&b);
	
	if (a==b) {
		printf("I due numeri sono uguali\n");
	} else if (a>b) {
		   printf("Maggiore %d e mnore %d\n",a,b);
		}
		else {
			printf("Maggiore %d minore %d\n",b,a);
		}
	 	
	return 0;
}
