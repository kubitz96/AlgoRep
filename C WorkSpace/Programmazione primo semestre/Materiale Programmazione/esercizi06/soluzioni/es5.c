#include <stdio.h>


void piu(int a1, int b1, int a2, int b2, int *p, int *q);
void meno(int a1, int b1, int a2, int b2, int *p, int *q);
void per(int a1, int b1, int a2, int b2, int *p, int *q);
void diviso(int a1, int b1, int a2, int b2, int *p, int *q);
void semplifica(int a, int b, int *p, int *q);
int mcd(int a, int b);
void stampaFrazione(int a, int b);


int main()
{
	int c, a1, b1, a2, b2, p, q;
	
	while ( c=getchar() && c!=EOF ) {
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		
		stampaFrazione(a1, b1); 
		printf(" %c ", c);
		stampaFrazione(a2, b2);
		printf(" = ");
		switch(c) {
			case '+': piu(a1,b1,a2,b2, &p, &q);
			          break;
			case '-': meno(a1,b1,a2,b2, &p, &q);
			          break;
			case '*': per(a1,b1,a2,b2, &p, &q);
			          break;
			case ':': diviso(a1,b1,a2,b2, &p, &q);
			          break;
		}

	}
}
