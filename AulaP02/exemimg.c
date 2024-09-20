#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"


int main(void)
{
    // Testando a função geraPixel
    srand((unsigned)time(NULL));
    printf("Pixels gerados (tipo -1): ( ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", geraPixel(-1));
    }
    printf("%d )\n ", geraPixel(-1));
    printf("Pixels gerados (tipo 0): ( ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", geraPixel(0));
    }
    printf("%d )\n ", geraPixel(0));
    printf("Pixels gerados (tipo 1): ( ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", geraPixel(1));
    }
    printf("%d )\n ", geraPixel(1));
    return 0;
}

