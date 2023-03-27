#include<stdio.h>
#include<stdlib.h>

#define MAX_NUMBERS 100

int readFile(const char *filename, float *v);
float *allocVect(int n);
void printVect(float *v, int n);
int removeElements(float *v, int n, float key);
float *orderVect(float *v, int n, float key1, float key2);

int main()
{
    float *V, *W;
    char filename[20];
    int nV;
    int remV;
    float k, k1, k2;

    V = allocVect(MAX_NUMBERS);

    puts("Inserire Nome File");
    scanf("%s", filename);

    nV = readFile(filename, V);

    puts("MATRICE V");
    printVect(V, nV);

    puts("Inserire Valore K");
    scanf("%f", &k);

    remV = removeElements(V, nV, k);

    puts("MATRICE V CON ELEMENTI MINORI DI K RIMOSSI");
    printVect(V, remV);

    puts("Inserire Valori K1(piu piccolo) e K2");
    scanf("%f%f", &k1, &k2);

    W = orderVect(V, remV, k1, k2);

    puts("MATRICE W CON ORDINATI");
    printVect(W, remV);

    free(W);
    free(V);
    return 0;
}

float *allocVect(int n)
{
    float *v;

    v = malloc(n*sizeof(float));

    return v;
}

int readFile(const char *filename, float *v)
{
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "r");

    while(!feof(fp))
    {
        fscanf(fp, "%f", &v[i]);
        i++;
    }

    fclose(fp);
    return i;
}

void printVect(float *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    puts("");
}

int removeElements(float *v, int n, float key)
{
    float *p;
    int i;

    p = allocVect(n);

    int index = 0;

    for (i = 0; i < n-1; i++)
    {
        if(v[i] >= key)
        {
        p[index] = v[i];
        ++index;
        }
        
    }

    for (i = 0; i <= index; i++)
    {
        v[i] = p[i];
    }
    
    free(p);

    return index;
}

float *orderVect(float *v, int n, float key1, float key2)
{
    int *flag;
    float *w;
    int i;
    int cnt1 = 0;
    int cnt2 = 0;
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    w = allocVect(n);
    flag = calloc(n,sizeof(int)); // SE DEVO FARE UN ARRAY DI FLAG DEVO FARE CALLOC

    for (i = 0; i < n; i++)
    {
        if(v[i] < key1)
        {
            flag[i] = 1;
            ++cnt1;
        }
        if(key1 <= v[i] && v[i] <= key2)
        {
            flag[i] = 2;
        ++cnt2;
        }
    }

    index2 = cnt1; index3 = cnt1 + cnt2;

    for (i = 0; i < n   ; i++)
    {
        if(flag[i] == 1)
        {
            w[index1] = v[i];
            index1++;
        }
        else if(flag[i] == 2)
        {
            w[index2] = v[i];
            index2++;
        }
        else
        {
            w[index3] = v[i];
            index3++;
        }
    }
    
    free(flag);

    return w;
}