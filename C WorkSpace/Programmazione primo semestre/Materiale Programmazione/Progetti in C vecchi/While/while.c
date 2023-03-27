#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int i;
int sum=0;

if(scanf("%d",&i) !=1) {
printf("no data found\n");
exit(1);}
if(i>5) {
printf("no data found\n");
exit(1);}
while(i<=5) {
sum += i;
++i;
printf("sum = %d\n", sum);}

return 0;

}
