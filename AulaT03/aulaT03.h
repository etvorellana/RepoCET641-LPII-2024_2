

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