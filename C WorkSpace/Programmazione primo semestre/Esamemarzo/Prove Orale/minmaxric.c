#include<stdio.h>
#include<stdlib.h>

int findmin(int *A, int n);
int findmax(int *A, int n);
int sumvect(int *A, int n);

int main()
{
    int *A;
    int n = 5;

    A  = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        A[i] = i;
    }
    

    int min;
    int max;
    int sum;

    min = findmin(A, n);
    max = findmax(A, n);
    sum = sumvect(A, n);

    printf("Il massimo e' %d e il minimo e' %d \n ", max, min);
    printf("la somma e' %d ", sum);

    free(A);
}

int findmin(int *A, int n)
{
    int min;
    if(n == 1) return A[0];

    min = findmin(A, n-1);

    if (A[n-1] < min) return A[n-1];
    return min;
}

int findmax(int *A, int n)
{
    int max;

    if (n == 1) return A[0];

    max = findmax(A, n-1);

    if(A[n-1] > max) return A[n-1];
    return max;
}

int sumvect(int *A, int n)
 {
    int sum = 0;
    if(n == 1) return A[0];
    return A[n-1] + sumvect(A,n-1);
 }