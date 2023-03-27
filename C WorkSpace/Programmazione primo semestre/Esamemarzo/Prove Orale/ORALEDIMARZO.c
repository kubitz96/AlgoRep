/*crea una funzione che data una matrice e un valore k, trovare tutte le sottomatrici quadrate k*k tale che:
trovato il minimo e il massimo nella sottomatrice, se la loro differenza e minore di 10 ritorna 1 se no ritorna 0.
*/

#include<stdio.h>
#include<stdlib.h>

int funzione(int **M, int m, int n, int k);         //all'orale mi è stato chiesto solo di scrivere su un foglio la definizione di questa funzione + una funziona ricorsiva di somma di elementi di un vettore

int main()
{
    int **A;
    int r = 10;     //è un caso che scelgo una matrice quadrata di partenza
    int c = 10;
    int check;      //valore di ritorno
    int k = 3;

    A = malloc(r*sizeof(int*));

    for (int i = 0; i < r; i++)
    {
        A[i] = malloc(c*sizeof(int));
    }
    
    for (int i = 0; i < r; i++)         //inizializzzo gli elementi a caso
    {
        for (int j = 0; j < c; j++)
        {
            A[i][j] = i+j;
        }
    }

    //A[2][2] = 14;  //con questo pongo il massimo della prima sottomatrice uguale a 14 quindi 14-0 = 14 quindi la funzione ritorna 0

    /* ogni sotto matrice 3*3 se faccio max-min uscira sempre 4 quindi ritorna 1
    (è un caso dato che la matrice ha un inizializzazione ben ordinata e non randomica)

    for (int i = 0; i < r; i++)         //stampo la matrice
    {
        for (int j = 0; j < c; j++)
        {
            printf("%3d", A[i][j]);
        }
        puts("");
    }

  0  1  2  3  4  5  6  7  8  9
  1  2  3  4  5  6  7  8  9 10
  2  3  4  5  6  7  8  9 10 11
  3  4  5  6  7  8  9 10 11 12
  4  5  6  7  8  9 10 11 12 13
  5  6  7  8  9 10 11 12 13 14
  6  7  8  9 10 11 12 13 14 15
  7  8  9 10 11 12 13 14 15 16
  8  9 10 11 12 13 14 15 16 17
  9 10 11 12 13 14 15 16 17 18
    */

    check = funzione(A, r, c, k);

    printf("Valore di ritorno della funzione = %d\n", check);

    for (int i = 0; i < r; i++)
    {
        free(A[i]);
    }
    free(A);
    
    return 0;

}

int funzione(int **M, int m, int n, int k)
{
    int max;
    int min;

    for (int i = 0; i < m-k; i++)       //faccio fino a -k perche oltre quel valore ottengo sottomatrici non piu quadrate
    {
        for (int j = 0; j < n-k; j++)
        {
            min = max = M[i][j];    //pongo il primo elemento della sottomatrice sia come min che max e poi confronto con tutti gli altri della sottomatrice quadrata

            for (int h = i; h < i+k; h++)       //questi altri due cicli for sono per scorrere ogni singola sottomatrice con gli indici ben configurati
            {
                for (int t = j; t < j+k; t++)
                {
                    if(M[h][t] == M[i][j]) continue;      //salto il primo elemento gia poichè fissato(vale solo per la prima riga prima colonna)
                    
                    if(M[h][t] < min) min = M[h][t];
                    if(M[h][t] > max) max = M[h][t];
                }
                if((max-min) > 10) return 0;
            }
        }
    }
    
    return 1;
}