#ifndef MATCALC_H
#define MATCALC_H

#define MAX_ROWS 10
#define MAX_COLS 10
void somma_vett(int vett1[], int vett2[], int n, int out[]);

int prod_scal(int vett1[], int vett2[], int n);

void somma_mat(int M1[][MAX_COLS], int n_r, int n_c,
               int M2[][MAX_COLS],
               int  S[][MAX_COLS]
              );

void prod_mat_vett(int M[][MAX_COLS], int n_r, int n_c,
                   int v[],
                   int p[]
              );
#endif 
