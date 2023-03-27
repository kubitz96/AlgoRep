#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	int count = 2;
	
	printf("Inserire un intero positivo ");
	scanf("%d", &n);
	
	if (n <=0 ) {
		exit(-1);
	}
	
	printf("%d: 1 ", n);
	
	for (i = 2; i<=n/2; i++) {
		if (n % i == 0) {
			printf("%d ", i);
			count++;
		}
	}
	printf("%d\n",n);
	
	if (count == 2) {
		printf("%d numero primo\n", n);
	}
}
