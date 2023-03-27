#include<stdio.h>

/*dato che 234 = 4*1 + 3*10 + 2*100
allora 1101 = 1*1 +0*2 +1*4+1*8*/
int main()
{
    int x, temp, dig;
    int resto, i = 1;
    int totale = 0;

    printf("Enter Total Digits --> "); //4
    scanf("%d", &dig);
    printf("Enter Binary Number --> "); //1101 sarebbe 13
    scanf("%d", &x);

 while (dig > 0)
  { 
     temp = x / 10;   // separo 110 da 1
     resto = (x % 10) * i;  // 1
     totale += resto;
     x = temp;    //ritorno 110
        --dig; //riduco dig a 3 e i diventa 2
     i *= 2;
  }
  printf("decimale %d", totale);
}