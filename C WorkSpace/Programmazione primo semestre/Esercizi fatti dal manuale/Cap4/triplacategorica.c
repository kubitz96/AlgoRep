#include<stdio.h>

int main()
{
    int lato1, lato2, ipotenusa;
    int quaipo, cnt = 1;

    printf("Numero\tTriple Pitagoriche\n");
    

    for(lato1 = 1; lato1 <= 500; ++lato1){
        for(lato2 = 1; lato2 <= 500; ++lato2){
            for(ipotenusa = 1; ipotenusa <=500; ++ipotenusa){ //controlli sempre nel for piu interno
                quaipo = ipotenusa*ipotenusa;
                if(quaipo == lato1*lato1 + lato2*lato2){  //verifica di valore è sempre "==" e non "="
                    printf("%d\t%d\t%d\t%d\n", cnt, lato1, lato2, ipotenusa);
                     ++cnt;
                }
            }
        }
    }

}