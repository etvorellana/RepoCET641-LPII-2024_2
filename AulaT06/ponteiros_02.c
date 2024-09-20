#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p;
    //alocando memódira
    p = malloc(4);
    printf("Endereço de p: %p\n", p);
    //desalocando memoria
    int* pInt = (int*)p;
    *pInt = 10;
    printf("Valor de p: %d\n", *pInt);
    float* pFloat = (float*)p;
    *pFloat = 10.5;
    printf("Valor de p: %f\n", *pFloat);
    char* pChar = (char*)p;
    *pChar = 'A';
    printf("Valor de p: %c\n", *pChar);
    pChar = "Amor";
    printf("Valor de p: %s\n", pChar);
    free(p);    
    return 0;
}