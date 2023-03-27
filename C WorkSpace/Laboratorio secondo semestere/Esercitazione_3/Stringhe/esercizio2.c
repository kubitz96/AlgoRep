//effettuare la copia di una stringa in un'altra senza utilizzare funzione string copy (strcpy)

 #define MAXLEN 100

#include<stdio.h>

int main()
{
	char str1[MAXLEN] = "Stringa";
	char str2[MAXLEN];

	for (int i = 0; str1[i] != '\0'; ++i)
	{
		str2[i] = str1[i];
	}

	printf("%s\n", str2);

	return 0;
}