#include <stdio.h>
#include <stdlib.h>


float **alloc_matrix(int m, int n)
{
  float **ptr;
  int i;

  ptr = (float **) malloc(m*sizeof(float *));

  if (ptr==NULL) return ptr;

  *ptr = (float *) malloc(m*n*sizeof(float));

  if (*ptr==NULL) {
    free((void *) ptr);
    return NULL;
  }

  for (i=1; i<m; i++) {
    ptr[i] = ptr[i-1] + n;
  }
  
  return ptr;
}


void free_matrix(float **ptr)
{
  free((void *) *ptr);
  free((void *) ptr);
}

void print_matrix(float **ptr, int m, int n)
{
  int i, j;

  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      printf("%f ", ptr[i][j]); 
    }
    printf("\n");
  }
}

int check_symmetry(float **A, int m, int n)
{
  int i, j;
  int symmetric = 1;

  for (i=0; i<m && symmetric; i++) {
    for (j=i+1; j<n && symmetric; j++) {
      symmetric = (A[i][j] == A[j][i]) ? 1 : 0;
    }
  }

  return symmetric;
}


int main()
{
  float **A;
  int m, n, i, j;

  scanf("%d %d", &m, &n);
  A = alloc_matrix(m,n);

  if (A==NULL) {
     exit(-1);
  }
  
  for (i=0; i<m; i++){
    for (j=0; j<n; j++) {
      scanf("%f",A[i]+j);
    }
  }

  printf("Symmetry: %d\n", check_symmetry(A,m,n));
  
  free_matrix(A);

  
}

for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
		if (a[i][j] != a[j][i]) return 0;
	}
}

return 1;

1 2 3 4
2 1 5 6
3 5 3 7
4 6 7 2

