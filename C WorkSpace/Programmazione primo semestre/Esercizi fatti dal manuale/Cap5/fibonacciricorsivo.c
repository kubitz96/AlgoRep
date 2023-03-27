#include<stdio.h>

int fibonacci(unsigned int numero);

int main()
{
    unsigned int n;

    printf("quale elemento della serie stampare\n");
    scanf("%d",&n);

    printf("Fibonacci(%u) = %u", n, fibonacci(n));

}

int fibonacci(unsigned int numero){
    if(0 == numero || 1 == numero) return numero;
    else {
        return (fibonacci(numero-1)+fibonacci(numero-2));
    }
}
