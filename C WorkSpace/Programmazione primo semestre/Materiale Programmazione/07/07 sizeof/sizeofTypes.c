/* Compute the size of some fundamental types. */

#include <stdio.h>

int main(void)
{
   printf("The size of some fundamental types is computed.\n\n");
   printf("       char:%3ld byte \n", sizeof(char));
   printf("      short:%3ld bytes\n", sizeof(short));
   printf("        int:%3ld bytes\n", sizeof(int));
   printf("       long:%3ld bytes\n", sizeof(long));
   printf("   unsigned:%3ld bytes\n", sizeof(unsigned));
   printf("      float:%3ld bytes\n", sizeof(float));
   printf("     double:%3ld bytes\n", sizeof(double));
   printf("long double:%3ld bytes\n", sizeof(long double));
   return 0;
}
