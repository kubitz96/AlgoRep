#include <stdio.h>

#define   LIMIT   46



int main(void)
{
	long f0, f1, somma;
	double q;
	int i;
	
	f0 = 0;
	f1 = 1;
   for (i=2; i< LIMIT; i++) {
	   somma = f1 + f0;
	   f0 = f1;
	   f1 = somma;
	   
	   q = ((double) f1)/f0;
	   printf("succession %ld quoziente %.15lf \n", f1, q);
   }
}
