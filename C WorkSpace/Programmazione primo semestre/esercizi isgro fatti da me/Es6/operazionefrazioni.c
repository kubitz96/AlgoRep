#include<stdio.h>
#include<stdlib.h>
#include<math.h>


 /* troppo lungo da fare manco il prof l' ha fatto
 void piu(int a1, int b1, int a2, int b2, int *p, int *q);
void meno(int a1, int b1, int a2, int b2, int *p, int *q);
void per(int a1, int b1, int a2, int b2, int *p, int *q);
void diviso(int a1, int b1, int a2, int b2, int *p, int *q);
void semplifica(int a, int b, int *p, int *q);
int mcd(int a, int b);
void stampaFrazione(int a, int b);
 */

int MCD(int n1, int n2);
int operazione(int a, int b, char op);
int semplificaPos(int a, int b, int p, int q);

int main()
{

}






int MCD(int n1, int n2)
{
    int min, max;
    int resto;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
    while((max % min) != 0)
    {
        resto= (max % resto);
        max= min;
        min= resto;
    } 
    return min;
}

int operazione(int a, int b, char op)
{
    switch (op)
    {
    case '+': return a+b;
        break;
    case '-': return a-b;
        break;
    case '*': return a*b;
        break;
    case ':': return a/b;
        break;
    
    default: puts("Carattere errato");
            exit(1);
    }
}

int semplificaPos(int a, int b, int p, int q)
{
}