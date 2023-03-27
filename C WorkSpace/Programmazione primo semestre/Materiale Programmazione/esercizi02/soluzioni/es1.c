#include <stdio.h>

#define ETA1	15
#define	ETA2	35
#define	ETA3	48
#define	ETA4	59
#define	ETA5	75
#define	ETA6	80

#define	PUNTI1	10
#define	PUNTI2	20
#define	PUNTI3	30


int main()
{
	int eta, punteggio;
	
	scanf("%d", &eta);
	
	while (eta <= 0) {
		printf("Devi inserire un numero positivo\n");
		scanf("%d", &eta);
	}
	
	if (eta <= ETA1 || (ETA4  < eta && eta <= ETA5) || eta > ETA6) {
		punteggio = PUNTI2;
	} else if ( (ETA1 < eta && eta <= ETA2) || ( ETA3 < eta  &&  eta <= ETA4) ) {
				punteggio = PUNTI1;
			}
			else {
				punteggio = PUNTI3;
			}
	
	printf("Punteggio assegnato ad %d  = %d\n", eta, punteggio);
	
	return 0;
}
