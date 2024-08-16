
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int valor;
    int aux;
    int d[10];
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    printf("O valor digitado foi: %d\n", valor);
    aux = valor;
    int cont = 0;
    while(aux > 0)
    {
        d[cont] = aux % 10;
        aux = aux / 10;
        cont++;
    }
    for(int i = cont-1; i >= 0; i--)
    {
        printf("%d,", d[i]);
    }
    printf("\n");

    for(int i = 0; i < cont-1; i++)
    {
        for(int j = i+1; j < cont; j++)
        {
            if(d[i] < d[j])
            {
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }

    for(int i = cont-1; i >= 0; i--)
    {
        printf("%d,", d[i]);
    }
    printf("\n");

    return 0;
}