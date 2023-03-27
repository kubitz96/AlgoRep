//implementare funzione string compare (strcmp)

 #define MAXLEN 100

#include<stdio.h>

int strcomp(char stringa1[], char stringa2[]);

int main()
{
	char str1[MAXLEN] = "Stringa";
	char str2[MAXLEN] = "Stringa";

	printf("%d\n", strcomp(str1, str2));

	return 0;
}

int strcomp(char stringa1[], char stringa2[])
{
	int i = 0;
	while(stringa1[i] == stringa2[i] && stringa1[i] != '\0')
	{
		++i;
	}
	if(stringa1[i] > stringa2[i]) return 1;
	else if(stringa1[i] < stringa2[i]) return -1;
	else return 0;

}