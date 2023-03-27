#include <stdio.h>

int main(void)
{
int x,y;

printf("inserisci due numeri interi per trovare maggiore e minore\n");
printf("primo intero -->");
scanf("%d",&x);
printf("secondo intero -->");
scanf("%d",&y);

if(x==y){
printf("I due numeri sono uguali\n");}
else if(x>y){
printf("%d e' maggiore di %d\n", x, y);}
else{
printf("%d e' minore di %d\n", x, y);}

return 0;
}
