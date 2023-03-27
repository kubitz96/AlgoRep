#include <stdio.h>

int main()
{
	int n;
	int somma = 0;
	int count = 0;
	

	while ( scanf("%d", &n) && n >= 0 ) {
		somma = somma + n;
		if (count > 0) {
			printf(" + \n");
		}
		printf("%8d", n);
		count++;
	}
	
	if (count > 0 ) {
		printf(" = \n");
		printf("___________\n");
		printf("%8d\n", somma);
	}
	
	return 0;
	
}
