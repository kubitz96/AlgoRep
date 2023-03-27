//determinare se un carattere inserito da tastiera è una vocale

#include<stdio.h>

int main()
{
    char c;

    puts("Inserire carattere");
    c =getchar();

    switch (c)
    {
    case 'a':
    case 'A':
        puts("e' una vocale");
        break;

    case 'e':
    case 'E':
        puts("e' una vocale");
        break;

    case 'i':
    case 'I':
        puts("e' una vocale");
        break;

    case 'o':
    case 'O':
        puts("e' una vocale");
        break;

    case 'u':
    case 'U':
        puts("e' una vocale");
        break;
    
    default:    puts("non e' una vocale");
        break;
    }

    return 0;
}