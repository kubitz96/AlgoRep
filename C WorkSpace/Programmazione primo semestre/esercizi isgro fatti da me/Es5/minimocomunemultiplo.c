#include<stdio.h>

int mcm(int n1, int n2);

int main()
{
    int x, y;
    
    printf("Inserire due Interi\n");
    scanf("%d%d", &x, &y);

    printf("mcm = %d", mcm(x,y));

    return 0;
}

int mcm(int n1, int n2)
{
    int min, max;
    int m;

    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;

    m = max;

    while(m % min != 0) m += max;

    return m;
}

/*Numeri dati: 4, 7
Come scritto prima, partiamo dal più grande, 7.
7 è divisibile per 4? No
Raddoppiamo. 14 è divisibile per 4? No
Triplichiamo. 21 è divisibile per 4? No
Andiamo oltre. 28 è divisibile per 4? Sì
Quindi, il mcm di 4 e 7 è 28*/