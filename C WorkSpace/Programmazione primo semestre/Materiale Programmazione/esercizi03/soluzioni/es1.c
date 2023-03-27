#include <stdio.h>

#define GENNAIO				1
#define	FEBBRAIO			2
#define	MARZO				3
#define APRILE				4
#define	MAGGIO				5
#define	GIUGNO				6
#define	LUGLIO				7
#define	AGOSTO				8
#define	SETTEMBRE			9
#define OTTOBRE				10
#define	NOVEMBRE			11
#define	DICEMBRE			12

#define GIORNI_GENNAIO		31
#define	GIORNI_FEBBRAIO		28
#define	GIORNI_FEBBRAIO_BIS	29
#define	GIORNI_MARZO		31
#define	GIORNI_APRILE		30
#define	GIORNI_MAGGIO		31
#define	GIORNI_GIUGNO		30
#define	GIORNI_LUGLIO		31
#define	GIORNI_AGOSTO		31
#define	GIORNI_SETTEMBRE	30
#define	GIORNI_OTTOBRE		31
#define	GIORNI_NOVEMBRE		30
#define	GIORNI_DICEMBRE		31
#define	GIORNI_ERRORE		-1
			




int isBisestile(int anno) 
{
	int bisestile;
	
	if ((anno % 400 == 0) || (anno%4 == 0 && anno%100 != 0 )) {
		bisestile = 1;
	}
	else {
		bisestile = 0;
	}

	return bisestile;
}


int giorniMese(int mese, int anno)
{
	int giorni;
	
	switch(mese) {
		case GENNAIO: giorni = GIORNI_GENNAIO;
					  break;
		case FEBBRAIO: if (isBisestile(anno)) giorni = GIORNI_FEBBRAIO_BIS;
					   else giorni = GIORNI_FEBBRAIO;
					   break;
		case MARZO: giorni = GIORNI_MARZO;
		            break;
		case APRILE: giorni = GIORNI_APRILE;
		             break;
		case MAGGIO: giorni = GIORNI_MAGGIO;
		             break;
		case GIUGNO: giorni = GIORNI_GIUGNO;
		             break;
		case LUGLIO: giorni = GIORNI_LUGLIO;
		             break;
		case AGOSTO: giorni = GIORNI_AGOSTO;
					  break;
		case SETTEMBRE: giorni = GIORNI_SETTEMBRE;
						break;
		case OTTOBRE: giorni = GIORNI_OTTOBRE;
		              break;
		case NOVEMBRE: giorni = GIORNI_NOVEMBRE;
				       break;
		case DICEMBRE: giorni = GIORNI_DICEMBRE;
		               break;
		default: giorni = GIORNI_ERRORE;
	}
	
	return giorni;
}

int main()
{
	
	int mese, anno;
	int giorni;
	int bisestile;
	
	printf("Inserisci mese --> ");
	scanf("%d", &mese);
	printf("Inserisci anno --> ");
	scanf("%d", &anno);
	
	/*
	bisestile = isBisestile(anno);
	giorni = giorniMese(mese, bisestile);
	if (giorni==GIORNI_ERRORE) {
		printf("Mese non valido\n");
	} else {
		printf("%d %d %d\n", mese, giorni, anno); 
	}
	* */
	//giorni = giorniMese(mese, isBisestile(anno));
	//printf("%d %d %d\n", mese, giorni, anno); 
	
	//giorni = giorniMese(mese, isBisestile(anno));
	
	giorni = giorniMese(mese, anno);
	return 0;
}
