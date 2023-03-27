#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void swap(char **p, char **q)
{
   char   *tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
