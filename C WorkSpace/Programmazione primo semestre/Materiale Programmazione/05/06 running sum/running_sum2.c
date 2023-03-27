/* Compute the minimum, maximum, sum, and average. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int      cont=0;
   double   x, min, max, sum, avg;
   
   while (scanf("%lf", &x) == 1) {
	   cont = cont + 1;
	   if (cont==1) {
		   sum = avg = min = max = x;
		   printf("%5s%9s%9s%9s%12s%12s\n%5s%9s%9s%9s%12s%12s\n\n",
			"Count", "Item", "Min", "Max", "Sum", "Average",
			"-----", "----", "---", "---", "---", "-------");
	   } else {
		   if (x<min) min = x;
		   else if (x > max)  max = x;
		   sum += x;
		   avg = sum/cont;
		}
		printf("%5d%9.1f%9.1f%9.1f%12.3f%12.3f\n",
			cont, x, min, max, sum, avg);
   }
   if (cont==0) {
	   printf("No data found - bye!\n");
   }
   
   return 0;
}
