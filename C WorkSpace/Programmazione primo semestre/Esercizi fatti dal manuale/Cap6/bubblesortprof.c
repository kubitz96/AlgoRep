#include <stdio.h>
#include <stdlib.h>

void   swap(int *p, int *q)
{
	int   tmp;
	
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void bubble(int *a, int n)     /* n is the size of a */
{
   int    i, j;

   for (i = 0; i < n - 1; ++i) {
	   for (j = n - 1; j > i; --j) {
		   if (a[j-1] > a[j]) {
			   swap(a+j-1, a+j);
			}
		}
	}
}

void printVect(int *a, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int v[] = {7, 3, 66, 3, -5, 22, -77, 2};
	
	
	printVect(v, 8);
	bubble(v, 8);
	printVect(v, 8);
}
