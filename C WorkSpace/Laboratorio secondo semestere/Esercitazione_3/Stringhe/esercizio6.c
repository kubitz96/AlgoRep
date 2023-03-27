//contare quanti caratteri maiuscoli sono presenti in una stringa

#define MAXLEN 100

#include<stdio.h>
#include<ctype.h>

int main()
{
	char stringa[MAXLEN] = "STRINGA da CONTROLLARE";
	int cnt = 0;

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		if(islower(stringa[i])) ++cnt;
	}

	printf("%d\n", cnt);

	return 0;
}