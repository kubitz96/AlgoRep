#include <stdio.h>

int main()
{
  char c;  int a;
  
  c = 'a'; a=10;
  printf("%c%c%c\n", c, c, c++);
  printf ("%d %d %d \n", a , a , a++);

  c = 'a'; a=10;
  printf("%c%c%c\n", c, c, ++c);
  printf("%d %d %d \n", a , a , ++a);

  c = 'a'; a=10;
  printf("%c%c%c\n", c, ++c, ++c);
  printf("%d %d %d \n", a , ++a , ++a);

  c = 'a'; a=10;
  printf("%c%c%c\n", c, c++, c++);
  printf("%d %d %d \n", a , a++ , a++);

  c = 'a'; a=10;
  printf("%c%c%c \n", ++c , c++ , c);
  printf("%d %d %d \n", ++a , a++ , a);
}
