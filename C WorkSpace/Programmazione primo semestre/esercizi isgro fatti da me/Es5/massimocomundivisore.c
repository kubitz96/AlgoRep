#include<stdio.h>

int MCD(int n1, int n2);

int main()
{
    int x, y;
    
    printf("Inserire due Interi\n");
    scanf("%d%d", &x, &y);

    printf("MCD = %d", MCD(x,y));

    return 0;
}

int MCD(int n1, int n2)
{
    int min, max;
    int resto;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
    while((max % min) != 0){
        resto= (max % resto);
        max= min;
        min= resto;
    } 
    return min;
}

/*Trovare il M. C. D. di 176 e 112:
Prima divisione:
176 : 112 = 1 con resto 64
Seconda divisione:
112 : 64 =1 con resto 48
64 : 48 = 1 con resto 16
48 : 16 = 3 con resto 0
Quindi, dato che l'ultimo divisore, prima dello zero, è 16, il Massimo Comun Divisore dei numeri 176 e 112 è appunto 16.
MCD (176, 112) = 16*/