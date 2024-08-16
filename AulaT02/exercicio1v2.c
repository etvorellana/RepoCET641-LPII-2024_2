
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
    aux = valor;
    d4 = aux % 10;
    aux = aux / 10;
    d3 = aux % 10;
    aux = aux / 10;
    d2 = aux % 10;
    aux = aux / 10;
    d1 = aux % 10;
    aux = aux / 10;
    d0 = aux % 10;
    printf("%d, %d, %d, %d, %d\n", d0, d1, d2, d3, d4);
    // primeira iteraçao
    if (d0 > d1)
    {
        // trocar os valores de d0 e d1
        aux = d0;
        d0 = d1;
        d1 = aux;
    }
    if(d1 > d2)
    {
        // trocar os valores de d1 e d2
        aux = d1;
        d1 = d2;
        d2 = aux;
    }
    if(d2 > d3)
    {
        // trocar os valores de d2 e d3
        aux = d2;
        d2 = d3;
        d3 = aux;
    }
    if(d3 > d4)
    {
        // trocar os valores de d3 e d4
        aux = d3;
        d3 = d4;
        d4 = aux;
    }
    // segunda iteraçao
    if (d0 > d1)
    {
        // trocar os valores de d0 e d1
        aux = d0;
        d0 = d1;
        d1 = aux;
    }
    if(d1 > d2)
    {
        // trocar os valores de d1 e d2
        aux = d1;
        d1 = d2;
        d2 = aux;
    }
    if(d2 > d3)
    {
        // trocar os valores de d2 e d3
        aux = d2;
        d2 = d3;
        d3 = aux;
    }
    // terceira iteraçao
    if (d0 > d1)
    {
        // trocar os valores de d0 e d1
        aux = d0;
        d0 = d1;
        d1 = aux;
    }
    if(d1 > d2)
    {
        // trocar os valores de d1 e d2
        aux = d1;
        d1 = d2;
        d2 = aux;
    }
    // quarta iteraçao
    if (d0 > d1)
    {
        // trocar os valores de d0 e d1
        aux = d0;
        d0 = d1;
        d1 = aux;
    }
    printf("%d, %d, %d, %d, %d\n", d0, d1, d2, d3, d4);



    return 0;
}