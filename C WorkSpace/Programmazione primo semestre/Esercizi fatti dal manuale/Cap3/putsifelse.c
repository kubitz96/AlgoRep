#include<stdio.h>

int main()
{
    int grade ;

    scanf("%d", &grade) ;

    puts(grade >= 60 ? "Passed" : "Failed" );

}