#include <stdio.h>

#include "aulaT03.h"

int main(void)
{
    int a, b, c;
    a = leiaValorInteiro('a');
    b = leiaValorInteiro('b');
    c = soma(a, b);
    printf("O valor de c é %d\n", c);
    
    return 0;
}



