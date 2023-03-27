#include<stdio.h>
//voto studente >= 90 voto A
//voto >= 80 voto B
//voto >=70 voto C
//voto >=60 voto D
// else F

int main()
{
    int voto ;

    scanf("%d", &voto) ;

    if(voto >= 90){
        puts("A") ;
    }
    else if(voto >= 80){
        puts("B") ;
    }
    else if(voto >= 70){            //in questo modo se si scrive if -- else if non vengono mai controllati tutti i casi ma solo quello giusto per primo 
        puts("C") ;
    }
    else if(voto >= 60){
        puts("D") ;
    }
    else {
        puts("F") ;
    }

    return 0 ;
}