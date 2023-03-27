
#include "matcalc.h"

void somma_vett(int vett1[], int vett2[], int n, int out[])
{
    for(int i = 0; i < n; i++)
        out[i] = vett1[i] + vett2[i];
}

int prod_scal(int vett1[], int vett2[], int n)
{
    int prod = 0;
    for(int i = 0; i < n; i++)
        prod = prod + vett1[i]*vett2[i];
    return prod;
}

void somma_mat(int M1[][MAX_COLS], int n_r, int n_c,
               int M2[][MAX_COLS],
               int  S[][MAX_COLS]
              )
{
    for(int i = 0; i < n_r; i++)
    {
        for(int j = 0; j < n_c; j++)
            S[i][j] = M1[i][j] + M2[i][j];

    }
}


void prod_mat_vett(int M[][MAX_COLS], int n_r, int n_c,
                   int v[],
                   int p[]
              )
{

    for(int i = 0; i < n_r; i++)
    {
        p[i] = 0;
        for(int j = 0; j < n_c; j++)
        {
            p[i] = p[i] + M[i][j]*v[j];
        
        }
    
    }

}
