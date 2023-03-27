//trasformazione stringa minuscola in maiuscola

#include<stdio.h>
#include<ctype.h>

#define MAXLEN 100

int main()
{
	char stringa[MAXLEN] = "stringa da TrAsFormaRE";

	for (int i = 0; stringa[i] != '\0';++i)
	{
		if(isupper(stringa[i])) stringa[i] += 32;
	}

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		printf("%c", stringa[i]);
	}
	printf("\n");

	return 0;
}