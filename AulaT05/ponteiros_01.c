#include <stdio.h>

int main() {
    void *p;
    int *pint;
    float *pfloat;

    int a = 5;
    float b = 5.5;

    pint = &a;
    pfloat = &b;

    printf("Endereco de a: %p\n", pint);
    printf("Endereco de b: %p\n", pfloat);
    printf("Conteudo de a: %d\n", *pint);
    printf("Conteudo de b: %f\n", *pfloat);
    printf("Tamanho de p: %lu\n", sizeof(p));
    printf("Tamanho de pint: %lu\n", sizeof(pint));
    printf("Tamanho de pfloat: %lu\n", sizeof(pfloat));

    int dou[2] = {1, 2};
    pint = dou;
    printf("Valor i = 0: %d\n", *pint);
    printf("Valor i = 0: %d\n", pint[0]);

    printf(": Valor i = 1: %d\n", pint[1]);
    printf(": Valor i = 1: %d\n", *(pint + 1));
    pint++;
    printf("Valor i = 1: %d\n", *pint);
    printf("Valor i = 0: %d\n", pint[0]);

    return 0;
}