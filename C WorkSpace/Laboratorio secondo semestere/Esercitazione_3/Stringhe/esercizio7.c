//dire in che posizione si trova il primo carattere maiuscolo

#define MAXLEN 100

#include<stdio.h>
#include<ctype.h>

int main()
{
	char stringa[MAXLEN] = "stringa dA controllare";
	int flag = 1;
	int posizione =-1;

	for (int i = 0;flag == 1 && stringa[i] != '\0'; ++i)
	{
		if(isupper(stringa[i]))
		{
			flag = 0;
			posizione = i;
		}
	}

	if(flag) printf("Sono tutte minuscole\n");
	else printf("La prima maiuscola in posizione %d\n", posizione);

	return 0;
}