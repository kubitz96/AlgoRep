#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[30];
	int *b;
	
	
	b = malloc(30*sizeof(int));
	
	
	printf("%ld %ld \n", sizeof(a), sizeof(b));
}

