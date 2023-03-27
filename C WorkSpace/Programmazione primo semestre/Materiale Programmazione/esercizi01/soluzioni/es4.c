#include <stdio.h>


int main()
{
	int a, b, c;
	
	printf("inserisci misura lato a --> ");
	scanf("%d",&a);
	printf("inserisci misura lato b --> ");
	scanf("%d",&b);
	printf("inserisci misura lato c --> ");
	scanf("%d",&c);
	
	if (a==b && b==c) {
		printf("Il triangolo e equilatero\n");
	} else if (a==b || b==c || a==c) {
				printf("Il triangolo e isoscele\n");
	       } else {
			   printf("Il triangolo e scaleno\n");
		   }
		   
    return 0;
}
