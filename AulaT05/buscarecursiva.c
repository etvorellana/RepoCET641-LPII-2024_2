#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preencher(int lista[], int n, int interval)
{
    
        
}   

int main(void)
{
    srand(time(NULL));
    printf("Procurando um elemento numa lista de tamanho %d\n", N);
    int lista[N];
    preencher(lista, N, 2*N);

    return 0;
}