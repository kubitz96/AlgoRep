/*scrivere un programma che stampi video la domanda cos'è un file .h? e,se l'utente risponde
 con una stringa contenente la parola libreria, il programma stampa bocciato, altrimenti Ok. Andiamo avanti.*/

#include<stdio.h>


int main()
{
	int flag = 1;

	printf("cos'e' un file .h?\n");

	char S[] = "libreria";
	char S2[9];

	scanf("%s", S2);

	for (int i = 0; i < 9 && flag; ++i)
	{
		if (S[i] != S2[i]) flag = 0;
	}

	if(flag) printf("bocciato\n");
	else printf("Ok, Andiamo avanti.\n");

	return 0;

}