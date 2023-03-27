#include <stdio.h>
					
int main(void)
{
int primo,secondo, numeri,i,prox;
	printf("scrivi quanti elementi della successione vuoi visualizzare\n");
	scanf("%d", &numeri);

		if(numeri<=0){
		printf("inserire numero positivo intero\n");
		scanf("%d", &numeri);
		}else if(numeri>0){
	primo=1;
	secondo=1;

	for(i=2; i<numeri;i++){
		prox=primo+secondo;
		primo=secondo;
		secondo=prox;

		printf("%d\n",primo);
		}

		
}
return 0;

}
