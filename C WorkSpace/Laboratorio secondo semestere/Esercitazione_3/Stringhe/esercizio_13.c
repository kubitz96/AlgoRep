/*Data una matrice contenente, in ogni riga, una stringa,
copiare in un vettore la prima lettera presente in ogni riga dopo averla convertita in maiuscolo*/

#include<stdio.h>
#include<ctype.h>

int main()
{
	char S[5][10] ={ "padre",
					 "madre",
					 "figlio",
					 "nonno",
					 "fratello"};

	char V[5];

	for (int i = 0; i < 5; ++i)
	{
		V[i] = toupper(S[i][0]);
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%c ",V[i]);
	}
	printf("\n");

	return 0;
}