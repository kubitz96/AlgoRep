#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TARIFFA 0.50

double calculate(float hours);

int main()
{
    float h, sumh= 0;
    double charge, sumc= 0;
    unsigned int n, i;

    printf("Inserire Numero Macchine \n");
    scanf("%u", &n);

    for(i = 1; i <=n; ++i){
        printf("ore --> ");
        if(scanf("%f", &h) != 1){
        puts("Errore");
        exit(1);
        }else{
            charge= calculate(h);
            if(i == 1) printf("%s%10s%10s\n", "Car", "Hours", "Charges");
            printf("%u%10.1f%10.2lf\n", i, h, charge);
            sumh += h;
            sumc += charge;
        }
    }
    printf("%s%10.1f%10.2lf", "TOTAL", sumh, sumc);
}

double calculate(float hours){
    double ch;
    if(hours <= 3) { ch= 2.00;
        return ch;
    }

    if(hours >= 24){ ch= 10.00;
    return ch;
    }
    else {
        ch= (ceil(hours - 3)) * TARIFFA + 2;  //arrotonda per eccesso
        return ch;
    }
}
