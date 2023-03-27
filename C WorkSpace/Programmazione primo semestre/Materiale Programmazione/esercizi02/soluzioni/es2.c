#include <stdio.h>

int isBisestile(int anno) 
{
	se bisestile return 1;
	else return 0;
}

int giorniMese(int mese, int bisestile)
{
	
	if (mese < 1 || mese > 12) errore();
	switch(mese) {
		case 11:
		case 4:
		case 6:
		case 9: giorni = 30;
				break;
		case 2: if (bisestile) giorni = 29;
				else giorni = 28;
		        break;
		default: giorni = 31;
	}
	
	return giorni;
}

int main()
{
	
	int mese, anno;
	
	//giorni = giorniMese(mese, anno);
	giorni = giorniMese(mese, isBisestile(anno));
	
	
}
