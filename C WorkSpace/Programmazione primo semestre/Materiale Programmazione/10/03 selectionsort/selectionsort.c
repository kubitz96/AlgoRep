#include <stdio.h>
#include <stdlib.h>

void   swap(int *p, int *q)
{
	int   tmp;
	
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void selection_sort(int *a, int n)     /* n is the size of a */
{
   int    i, j;

   for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n ; j++)
         if (a[j] < a[i])
            swap(a+j, a+i);
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
	selection_sort(v, 8);
	printVect(v, 8);
}
