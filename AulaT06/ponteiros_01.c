#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p;
    //alocando memódira
    p = malloc(4);
    printf("Endereço de p: %p\n", p);
    //desalocando memoria
    free(p);    
    return 0;
}