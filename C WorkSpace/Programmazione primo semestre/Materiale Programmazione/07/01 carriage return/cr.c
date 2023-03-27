#include <stdio.h>

#define PAUSA 2000000

void pausa(int l)
{
	int i;
	for (i=0; i<l; i++);
}

int main()
{
	setbuf(stdout, 0);
	while(1) {
		printf("|\r"); pausa(PAUSA); 
		printf("/\r"); pausa(PAUSA); 
		printf("-\r"); pausa(PAUSA); 
		printf("\\\r"); pausa(PAUSA); 
		
	}
}
