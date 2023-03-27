#include <stdio.h>
#define ETA1 15
#define ETA2 35
#define ETA3 48
#define ETA4 59
#define ETA5 75
#define ETA6 81
#define P10	 10
#define P20	 20
#define P30	 30

int main(void)
{
	int eta,punti;
	scanf("%d",&eta);

	while(eta<=0) {
		printf("eta non valida,riprovare\n");
		scanf("%d",&eta);}

	if (eta<=ETA1 || eta>=ETA6) {
		punti=P20;}
	else if(eta>ETA1 && eta<=ETA2 || eta>ETA3 && eta<=ETA4){
		punti=P10;}
	else{punti=P30;}

	printf("Eta' %d -->%d PUNTI\n", eta,punti);

	return 0;
	}
