#include<stdio.h>
#define SIZE 10

size_t linearsearch(int b[], int key, int size);
void printarray(int b[], int size);

int main()
{
    int a[SIZE];
    int k;

    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] = i * 2;
    }
    
    puts("Enter Key Number");
    scanf("%d", &k);
    int index = linearsearch(a, k, SIZE);

    if(index != EOF) printf("The key %d is at %d index\n", k, index);
    else puts("Value not Found");
    printarray(a, SIZE);

    return 0;
}

size_t linearsearch(int b[], int key, int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if(b[i] == key) return i;
    }
    return EOF;
        
}

void printarray(int b[], int size)
{
    printf("%s%13s\n", "Index", "Value");
    for (size_t l = 0; l < size; ++l)
    {
        printf("%5u%13d\n", l, b[l]);
    }
    puts("");
}