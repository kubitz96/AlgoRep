//contare quanti vocali e consonanti sono presenti in una stringa

#include<stdio.h>

#define MAXLEN 100

int isvowel(char letter);

int main()
{
	char stringa[MAXLEN] = "Stringa";
	int cntv = 0;
	int cntc = 0;

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		if(isvowel(stringa[i])) ++cntv;
		else if(stringa[i] == ' ' || stringa[i] == '\n');
		else ++cntc;
	}

	printf("Vocali %d, Consonanti %d\n", cntv, cntc);

	return 0;
}

int isvowel(char letter)
{
	switch(letter)
	{
		case 'a':
		case 'A':
		break;

		case 'e':
		case 'E':
		break;

		case 'i':
		case 'I':
		break;

		case 'o':
		case 'O':
		break;

		case 'u':
		case 'U':
		break;

		default: return 0;
		break;
	}

	return 1;
}