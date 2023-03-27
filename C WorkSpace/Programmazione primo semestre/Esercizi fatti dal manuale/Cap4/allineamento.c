#include<stdio.h>

int main()
{
    printf("%8s\n", "aaa");
    printf("%-8s\n", "aaa");
    printf("%8s%8s\n", "aaa", "aaa");
    printf("%8s%-8s\n", "aaa", "aaa");
    printf("%-8s%8s\n", "aaa", "aaa");
}