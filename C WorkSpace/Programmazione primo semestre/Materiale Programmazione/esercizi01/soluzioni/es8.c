#include <stdio.h>

#define SEC_IN_ORA		3600
#define SEC_IN_MINUTO	60

int main()
{
	int ore, minuti, secondi;
	int durata;
	
	ore = durata/SEC_IN_ORA;
	durata = durata % SEC_IN_ORA;
	minuti = durata/SEC_IN_MINUTO;
	durata = durata % SEC_IN_MINUTO;
	secondi = durata;
	
	return 0;
}
