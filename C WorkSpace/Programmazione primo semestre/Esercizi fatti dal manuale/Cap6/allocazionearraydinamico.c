/*
  Allocazione di un array dinamico.
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
  int *a;
  int d;

  printf("Quanti elementi? ");
  scanf("%d", &d);

  a=malloc(d*sizeof(int)); //(int*)calloc(d,sizeof(int) inizializza gli altri elementi non iniziallizati a 0.

  a[0]=12;
  a[1]=a[0]+40;

    for(size_t i = 0; i < d; ++i)   
    {
        printf("%7u%13u\n", i, a[i]);
    }

    free(a); //liberare la memoria

  return 0;
}