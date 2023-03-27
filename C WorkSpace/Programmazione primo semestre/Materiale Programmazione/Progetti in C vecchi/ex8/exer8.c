#include <stdio.h>

#define ORAINSECONDI		3600
#define MINUTOINSECONDI		60

int main(void)
{
int tempo,secondi,minuti,ore;

printf("tempo -->");
scanf("%d",&tempo);

ore=tempo/ORAINSECONDI;
tempo=tempo%ORAINSECONDI;
minuti=tempo/MINUTOINSECONDI;
tempo=tempo%MINUTOINSECONDI;
secondi=tempo;

printf("%dh %dmin %dsec\n",ore,minuti,secondi);

return 0;
}

