#include<stdio.h>
#define SIZE_STR3 20

int main()
{
    char string1[] = "First";
    char string2[] = {'S', 'e', 'c', 'o', 'n', 'd', '\0'};

    for (size_t i = 0; string1[i] != '\0'; ++i)
    {
        printf("%c", string1[i]);
    }

    printf("\n%s\n", string1);
    
        for (size_t i = 0; string2[i] != '\0'; ++i)
    {
        printf("%c", string2[i]);
    }

    puts("");

    char string3[SIZE_STR3];

    puts("Inserisci una stringa di 19 caratteri massimo");
    scanf("%19s", string3); //diciannovecaratteri
    
        for (size_t i = 0; string3[i] != '\0'; ++i)
    {
        printf("%c", string3[i]);
    }
}