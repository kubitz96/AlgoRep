/*implementare una funzione che, data in input una stringa, restituisca due variabili,
 la prima contenente la prima consonante presente nella stringa, la seconda variabile contenente l'ultima vocale.*/

#include<stdio.h>

int isvowel(char letter);
void stringaf(char *a, char *b);

int main()
{
	char vocale, consonante;
	stringaf(&vocale, &consonante);

	printf("Prima consonante %c, ultima vocale %c\n", consonante , vocale);

	return 0;
}

void stringaf(char *a, char *b)
{
	char stringa[20];
	printf("Inserire una stringa\n");
	scanf("%s", stringa);
	int flag = 0;

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		if(flag == 0 && isvowel(stringa[i]) == 0)
			{
				*b = stringa[i];
				flag = 1;
			}
			
		if(isvowel(stringa[i])) *a = stringa[i];
	}
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