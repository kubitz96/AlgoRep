#include<stdio.h>               
#include<stdlib.h>

#define MAX_ELEMENTS 1000

#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30

float *readFile(const char *filename, float *V, int *nV);
float *allocVect(int n);
void errorManager(int code);
void printVect(float *V, int n);
int removeElements(float *V, int n, float key);
float *newVect(float *V, int nV, float key1, float key2);  
void writeFile(const char *outname, float *A, int n);

int main()
{
    float *A, *B;
    int nA;
    float k, k1, k2;
    char filename[FILENAME_MAX];
    char outname[FILENAME_MAX];

    puts("Enter Filename");
    scanf("%s", filename);

    A = readFile(filename, A, &nA);

    puts("Vect A read in File");
    printVect(A, nA);

    puts("Enter K value");
    scanf("%f", &k);

    nA = removeElements(A, nA, k);

    puts("Vect A with elements lower than K value removed");
    printVect(A, nA);

    puts("Enter K1 and K2 values");
    scanf("%f%f", &k1, &k2);

    B = newVect(A, nA, k1, k2); 

    puts("New vect B with ordered elements");
    printVect(B, nA);

    puts("Enter Filename to Write vect B");     
    scanf("%s", outname);
    writeFile(outname, B, nA);

    free(A);
    free(B);

    return 0;

}

float *readFile(const char *filename, float *V, int *nV)
{
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "r");

    if(fp == NULL) errorManager(READ_FILE_ERROR);

    V = allocVect(MAX_ELEMENTS);

    while(!feof(fp))
    {
        fscanf(fp, "%f", &V[i]);
        i++;
    }

    fclose(fp);
    *nV = i;
    return V;
}

float *allocVect(int n)
{
    float *v;

    v =(float*) calloc(n,sizeof(float));

    if(v == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    return v;
}

void printVect(float *V, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", V[i]);
    }
    puts("");
}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory!\n");
        break;

    case READ_FILE_ERROR:
        fprintf(stderr, "Reading File Error!\n");
        break;

    case WRITE_FILE_ERROR:
        fprintf(stderr, "Writing File Error!\n");
        break;

    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }
    exit(-1);
}

int removeElements(float *V, int n, float key)
{
    int *fl;

    fl = calloc(n,sizeof(int));
    if(fl == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    for (int i = 0; i < n; i++)
    {
        if(V[i] < key) fl[i] = 1;
    }
    
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if(fl[i] != 1)
        {
            V[index] = V[i];
            ++index;
        }
    }

    free(fl);
    return index;
}

float *newVect(float *V, int nV, float key1, float key2)    
{
    float *W;               
    int *fl;
    int cnt1 = 0;
    int cnt2 = 0;
    int index1, index2, index3, i;

    W = allocVect(nV);       

    fl = calloc(nV,sizeof(int));
    if(fl == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    for (i = 0; i < nV; i++)
    {
        if(V[i] < key1)
        {
            fl[i] = 1;
            ++cnt1;
        }
        else if(V[i] >= key1 && V[i] <= key2)
        {
            fl[i] = 2;
            ++cnt2;
        }
    }
    
    index1 = 0; index2 = cnt1; index3 = cnt1 + cnt2;

    for (i = 0; i < nV; i++)
    {
        if(fl[i] == 1)
        {
            W[index1] = V[i];
            index1++;
        }
        else if(fl[i] == 2)
        {
            W[index2] = V[i];
            index2++;
        }
        else
        {
            W[index3] = V[i];
            index3++;
        }
    }
    
    free(fl);

return W;
}

void writeFile(const char *outname, float *A, int n)
{
    FILE *fp;
    int i;

    fp = fopen(outname, "w");

for (i = 0; i < n; i++)
{
    fprintf(fp, "%.2f ", A[i]);
}

fclose(fp);

}