#include<stdio.h>

int main()
{
    int i, j, space;

    for(i = 1; i <= 10; ++i){  
        for(j = 1; j <=i; ++j) printf("%s", "*");
        puts("");
    }
    for(i = 10; i >= 1; --i){  
        for(j = 1; j <=i; ++j) printf("%s", "*");
        puts("");
    }
    for(i = 10; i >= 1; --i){  //ciclo per asterischi per riga

        for(space = 1; space <=10-i; ++space) printf("%s", " ");

        for(j = 1; j <=i; ++j) printf("%s", "*");
            
        puts("");
    
    }
    for(i = 1; i <=10; ++i){

        for(space = 10 ; space > i; --space) printf("%s", " ");
        for(j = 1; j <=i; ++j) printf("%s", "*");
        puts("");
    }
}