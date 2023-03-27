//Stampare l’alfabeto delle minuscole invertito, ossia dalla z alla a

#include<stdio.h>

int main()
{
    for (int i = 122; i >= 97; i--)
    {
        printf("%c ", i);
    }
    
    return 0;
}
