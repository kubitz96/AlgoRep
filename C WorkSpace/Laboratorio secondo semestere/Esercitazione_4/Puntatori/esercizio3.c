/*implementare due funzioni:

lock(...): accetta come parametro una variabile di tipo int; se questa variabile è  ≠0  ,la mette a 0 e restituisce 1 (ossia operazione andata a buon fine);
 se è ==0 la si lascia a zero e si restituisce 0 (ossia operazione non effettuata perchè, appunto, inutile in quanto la variabile già è a 0 )
unlock(...): accetta una variabile di tipo int; se questa variabile è ==0, la mette a 1 e si restituisce 1 ; se la variabile è  ≠0  la si lascia al valore che ha e si restituisce 0.
Esempio di main():
int a = 1;
int r;
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 1
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 0
r = unlock(&a);
printf("esito operazione: %d\n", r); // stamperà 1
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 1*/

#include<stdio.h>

int lock(int *n);
int unlock(int *n);

int main()
{
	int a = 1;
int r;
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 1
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 0
r = unlock(&a);
printf("esito operazione: %d\n", r); // stamperà 1
r = lock(&a);
printf("esito operazione: %d\n", r); // stamperà 1

return 0;
}

int lock(int *n)
{
	if(*n != 0)
	{
		*n = 0;
		return 1;
	}
	else return 0;
}

int unlock(int *n)
{
	if(*n == 0)
	{
		*n = 1;
		return 1;
	}
	else return 0;
}