//verificare se una stringa è composta da soli caratteri maiuscoli

#define MAXLEN 100

#include<stdio.h>
#include<ctype.h>

int main()
{
	char stringa[MAXLEN] = "stringa da controllare";
	int flag = 1;

	for (int i = 0;flag == 1 && stringa[i] != '\0'; ++i)
	{
		if(isupper(stringa[i])) flag = 0;
	}

	if(flag) printf("Sono tutte minuscole\n");
	else printf("C'è almeno una maiuscola\n");

	return 0;
}