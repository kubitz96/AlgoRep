#include<stdio.h>

int main()
{
    int a[5] = {0, 1, 2, 3, 4,};

    for (size_t i = 0; i < 5; i++) // uguale a ++i in questo caso perche in realtà io sto operando con la i che viene comunque incrementata a ogni ciclo
    {
        printf("%d", a[i]);
    }
    
    scanf("%d", &a[3]); //se scrivo il vettore staticamente ogni a[n] e' considerata una singola variabile
    printf("%d", a[3]);

    
}
