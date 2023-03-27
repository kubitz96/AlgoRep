#include <stdio.h>

#define NELEMENTI	4

int main()
{
	int n;
	int count = 0;
	
	scanf("%d", &n);
	while (n != 0) {
		count++;
		
		printf("%6d", n);
		
		//if (count % NELEMENTI == 0) printf("\n");
		if (count == 4) {
			printf("\n");
			count = 0;
		}
		
		scanf("%d", &n);
	}
	printf("\n");
}
