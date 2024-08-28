#include <stdio.h>
#include "random.h"

int main(void)
{
    printf("O valor inteiro aleatório %d\n", geraInt(1, 10));
    printf("O valor real aleatório %f\n", geraReal(1.0, 10.0));
    return 0;
}