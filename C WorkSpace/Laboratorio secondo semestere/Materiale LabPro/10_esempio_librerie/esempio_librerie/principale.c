#include <stdio.h>
#include "matio.h"
#include "matcalc.h"


int main()
{
    int M1[][MAX_COLS] = {
                          {1,2},
                          {3,4},
                          {5,6}
                         };
    int M2[][MAX_COLS] = {
                          {10,20},
                          {30,40},
                          {50,60}
                         };
    

    
    printf("M1:\n");
    stampa_mat(M1,3,2);

    printf("M2:\n");
    stampa_mat(M2,3,2);
    int S[MAX_ROWS][MAX_COLS];
    somma_mat(M1,3,2,M2,S);
    printf("M1 + M2 =\n");
    stampa_mat(S, 3,2);
    
    int v[] = {7,8};
    printf("v:\n");
    stampa_vett(v,2);

    int p[MAX_ROWS];
    prod_mat_vett(M1, 3, 2, v, p);
    printf("M1v = \n");
    stampa_vett(p, 3);
    
    return 0;
}




