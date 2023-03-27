//Data una stringa s ed un'altra stringa q, verificare se q è una sottostringa di s

#include<stdio.h>
#include<string.h>

int main()
{
	char s[] = "passaparola";
	char q[] = "parola";

	int sotto = 0;

	
	for (int i = 0; s[i] != '\0' && sotto == 0; ++i)
	{
		int flag = 1;

		for (int j = 0, h = i; q[j] != '\0' && flag; ++j)
		{
			if(q[j] != s[h]) flag = 0;
			else ++h;
		}

		if(flag) sotto = 1;
	}

	if(sotto) printf("e' sottostringa\n");
	else printf("No\n");

	return 0;
}