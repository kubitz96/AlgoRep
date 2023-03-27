#include<stdio.h>
#define SIZE_ARRAY 10

void printarray(int b[], int size);
void bubblesort(int b[], int size);

int main()
{
    int a[SIZE_ARRAY] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    printarray(a, SIZE_ARRAY);
    bubblesort(a, SIZE_ARRAY);
    printarray(a, SIZE_ARRAY);
}

void printarray(int b[], int size)
{
    printf("Array = ");
    for (size_t l = 0; l < size; ++l)
    {
        printf("%3d", b[l]);
    }
    puts("");
}
void bubblesort(int b[], int size)
{
     for (unsigned int p = 1; p < SIZE_ARRAY; ++p) // servono piu passate perche un numero piccolo torna indietro solo una volta
    {
        for (size_t i = 0; i <  SIZE_ARRAY-1; ++i)
        {
            if(b[i] > b[i+1])
            {
            int tmp;
            tmp = b[i];
            b[i] = b[i+1];
            b[i+1] = tmp;
            }
        }
    }
}
