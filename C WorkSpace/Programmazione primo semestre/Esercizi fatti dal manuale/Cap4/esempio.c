#include<stdio.h>

int main()
{
for (unsigned int i = 1; i <= 5; ++i) { // volte che stampa tabelle
    for (unsigned int j = 1; j <= 3; ++j) { //riga
        for (unsigned int k = 1; k <= 4; ++k) { //colonna
        printf("%s", "*");
        }
        puts("");
    }
    puts("");
}
}