
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int valor;
    int aux;
    int d0, d1, d2, d3, d4;
    printf("Digite um valor inteiro de 5 dígitos: ");
    scanf("%d", &valor);
    printf("O valor digitado foi: %d\n", valor);
    d0 = valor / 10000;
    printf("D0: %d\n", d0);
    aux = valor % 10000;
    d1 = aux / 1000;
    printf("D1: %d\n", d1);
    aux = aux % 1000;
    d2 = aux / 100;
    printf("D2: %d\n", d2);
    aux = aux % 100;
    d3 = aux / 10;
    printf("D3: %d\n", d3);
    d4 = aux % 10;
    printf("D4: %d\n", d4);

    return 0;
}