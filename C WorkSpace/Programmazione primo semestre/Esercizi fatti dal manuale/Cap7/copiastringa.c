#include<stdio.h>
#include<stdlib.h>

void copystring(char *p,char *q);

int main()
{
    char *string1;

    char *string2 = "Ciao";

    copystring(string1, string2);

    printf("%s", string1);
}

void copystring(char *p,char *q)
{
    while ((*p = *q) != '\0')  //scrivendo *p mi riferisco a cosa è contenuto in p[0]
    {
        ++p, ++q;
    }
    
}