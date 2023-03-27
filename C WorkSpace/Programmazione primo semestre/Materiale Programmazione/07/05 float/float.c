#include <stdio.h>

int main()
{  
   float x;
      
   x = 1e-37; printf("x = 1e-37    x = %e\n", x);
   x = 1e-38; printf("x = 1e-38    x = %e\n", x);
   x = 1e-39; printf("x = 1e-39    x = %e\n", x);
   x = 1e-40; printf("x = 1e-40    x = %e\n", x);
   x = 1e-41; printf("x = 1e-41    x = %e\n", x);
   x = 1e-42; printf("x = 1e-42    x = %e\n", x);
   x = 1e-43; printf("x = 1e-43    x = %e\n", x);
   x = 1e-44; printf("x = 1e-44    x = %e\n", x);
   x = 1e-45; printf("x = 1e-45    x = %e\n", x);
   x = 1e-46; printf("x = 1e-46    x = %e\n", x);

   x = 1e38; printf("x = 1e38    x = %e\n", x);
   x = 1e39; printf("x = 1e39    x = %e\n", x);
   
   x = 123.45123451234512345;
   printf("x = 123.45123451234512345     x = %3.17f\n x = %e", x, x);
}
