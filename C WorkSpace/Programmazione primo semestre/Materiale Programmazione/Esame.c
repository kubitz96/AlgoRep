#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int **Read_File(const char *fileName, int *m, int *n);
int **Alloc_Matrix(int m, int n);
void Errore_Matrix();
void Errore_File();
void Free_Matrix(int **A);
void Print_Matrix(int **A, int m, int n);
void Matrix_Magica(int **A, int n);
int **Esercizio_C(int **A, int m, int n);
void Write_File(const char *fileName, int **M, int m, int n);

int main(int argc, char *argv[]) 
{
	int **A;//matrice
	//m righe n colonne
	int m;
	int n;

	A=Read_File("esame.txt",&m,&n);

	if (m==n)
	{
		Matrix_Magica(A,n);
	}
	else
	{
		printf("\n matrice non quadrata, impossibile verificare la matrice magica");
	}
	A=Esercizio_C(A,m,n);
	Write_File("esame.txt",A,m,n);
	Free_Matrix(A);
	return 0;
}

int **Read_File(const char *fileName, int *m, int *n)
{
	FILE *fp;
	int valore;//valore letto nel file
	int Mrigha;//righa letto nel file
	int Ncolonna;//colonna letto nel file
	int **A;
	
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		Errore_File();
	}
	fscanf(fp, "%d%d", n, m);
	A=Alloc_Matrix(*m,*n);
	
	while(!feof(fp))
	{
		fscanf(fp,"%d", &valore);
		fscanf(fp,"%d", &Mrigha);
		fscanf(fp,"%d", &Ncolonna);

		A[Mrigha-1][Ncolonna-1]=valore;
	}
	Print_Matrix(A,*m,*n);
	
	return A;
}

int **Alloc_Matrix(int m, int n)
{
 	int **A, i,j;
	
	A = (int **) malloc(m*sizeof(int *));
	if (A == NULL) {
		Errore_Matrix();
	}
	
	A[0] = (int *) malloc(m*n*sizeof(int));
	if (A[0] == NULL) 
	{
		Errore_Matrix();
	}
	
	for (i=1; i<n; i++) 
	{
		A[i] = A[i-1] + n;
	}
	
	
	for (i=0;i<n;i++)
	{
		for(j=0; j<m;j++)
		{
			A[i][j]=0;
		}
	}
	
	return A;
}

void Print_Matrix(int **A, int m, int n)
{
  int i, j;
  for (i=0; i<n; i++)
   {
    for (j=0; j<m; j++) 
	{
     	printf("%d ", A[i][j]); 
    }
    printf("\n");
  }
}

void Matrix_Magica(int **A,int n)
{
	int i,j,t;
	int confronto= 1;
	int sommadp=0;//diagonale prima
	int sommads=0;//diagonale seconda
	int somma1=0;
	int somma2=0;
	i=0;
	while(confronto== 1 && i<n)//controllo se tutti gli elementi sono distinti 
	{
		j=1;
		while(confronto== 1 && j<n)
		{
			if(A[i][j-1]== A[i][j])
			{
				confronto= 0;
			}
			j++;
		}
		i++;
	}
	
	if(confronto == 1)
	{
		for (i=0;i<n;i++)//somma diagonale prima
		{
			sommadp= A[i][i]+ sommadp;
		}
		j=n-1;
		for(i=0;i<n;i++) //somma diagonale seconda
		{
			sommads= A[i][j] + sommads;
			j--;
		}
		if(sommads==sommadp)
		{
			for(t=0;t<n;t++)
			{
				for(i=0;i<n;i++)
				{	
					somma1= A[t][i] +somma1;
				}
				for(i=0;i<n;i++)
				{
					somma2 = A[i][t]+somma2;
				}
				if(somma1 != somma2 || somma1!= sommadp || somma2 != sommadp)
				{	
					confronto=0;
				}
				else
				{
					somma1=0;
					somma2=0;
				}
			}
		}
		else 
		{
				
		confronto =0;
		}

		if(confronto==0)
		{
		
		printf("\n la matrice non e' magica");	
		}
		else
		{
			printf("\n la matrice e' magica");	
		}
	}
	else
	{
		printf("\n la matrice non e' magica");
	}
}


int **Esercizio_C(int **A, int m, int n)
{
	int i,j;
	int restoj,restoi;
	
   for (i=0; i<n; i++)
    {
    	for (j=0; j<m; j++) 
		{
   	 	 	if(A[i][j]%j==0 || A[i][j]%i==0 )
   	 	 	{
   	 	 		A[i][j]=0;
   	 	 		
			}
   		}
   }
 
   return A;
}


void Write_File(const char *fileName, int **A, int m, int n)
{
	FILE *fp;
	int i, j;
	
	fp = fopen(fileName, "w");
	if (fp == NULL)
	{
		Errore_File();
	}
	
	fprintf(fp, "%d %d\n", m, n);
	
	for (i=0; i<m; i++) 
	{
		for (j=0; j<n; j++) 
		{
			fprintf(fp, "%d %d %d\n",A[i][j],i,j);
		}
	}
	
	fclose(fp);
}
void Free_Matrix(int **A)
{
	free(A[0]);
	free(A);
}

void Errore_Matrix()
{
	printf("Errore allocazione matrice");
	exit(-1);
}

void Errore_File()
{
	printf("Errore apertura file");
	exit(-1);
}
