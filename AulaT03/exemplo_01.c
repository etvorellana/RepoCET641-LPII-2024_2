#include <stdio.h>

int main(void) {

    int a, b, c;
    a = leiaValorInteiro('a');
    b = leiaValorInteiro('b');
    c = soma(a, b);
    printf("O valor de c é %d\n", c);
    
    return 0;
}


int leiaValorInteiro(char op)
{
    int x;
    printf("Digite um valor inteiro para %c: ", op);
    scanf("%d", &x);
    return x;
}

int soma(int a, int b)
{
    printf("A soma de %d e %d é %d\n", a, b, a + b);
    return a + b;
}