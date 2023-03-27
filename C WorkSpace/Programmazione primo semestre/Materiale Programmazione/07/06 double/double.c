#include <stdio.h>

int main()
{  
 double x;
      
   x = 1e-307; printf("x = 1e-307    x = %e\n", x);
   x = 1e-308; printf("x = 1e-308    x = %e\n", x);
   x = 1e-309; printf("x = 1e-309    x = %e\n", x);
   x = 1e-400; printf("x = 1e-400    x = %e\n", x);
   x = 1e-401; printf("x = 1e-401    x = %e\n", x);
   x = 1e-402; printf("x = 1e-402    x = %e\n", x);
   x = 1e-403; printf("x = 1e-403    x = %e\n", x);
   x = 1e-404; printf("x = 1e-404    x = %e\n", x);
   x = 1e-405; printf("x = 1e-405    x = %e\n", x);
   x = 1e-406; printf("x = 1e-406    x = %e\n", x);

   x = 1e308; printf("x = 1e308    x = %e\n", x);
   x = 1e309; printf("x = 1e309    x = %e\n", x);
   
   x = 123.45123451234512345;
   printf("x = 123.45123451234512345     x = %.17e\n", x);
}
