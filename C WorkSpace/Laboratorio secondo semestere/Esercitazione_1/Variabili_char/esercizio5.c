/*far acquisire all’utente due numeri in due variabili di tipo float ed un simbolo in una variabile
di tipo char; se la variabile di tipo char ha al suo interno il simbolo ‘+’, stampare la somma
delle due variabili, se invece ha al suo interno il simbolo ‘-’, stampare la differenza delle due
variabili, in tutti gli altri casi stampare “non posso farlo”*/

#include<stdio.h>

int main()
{
    float a, b;
    char c;

    puts("Inserire due numeri a e b e segno + o -");
    scanf("%f%f %c", &a, &b, &c);

    switch (c)
    {
    case '+':
        printf("%.2f", a+b);
        break;

    case '-':
        printf("%.2f", a-b);
        break;
    
    default:    puts ("non e' possibile farlo");
        break;
    }
}
