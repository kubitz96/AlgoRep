//data una stringa e due variabili carattere C1 e C2, sostituire nella stringa tutte le occorrenze di C1 con C2

#include<stdio.h>

int main()
{
	char stringa[] = "pippo";

	char C1 = 'p';
	char C2 = 'b';

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		if(stringa[i] == C1) stringa[i] = C2;
	}

	printf("%s\n", stringa);

	return 0;
}