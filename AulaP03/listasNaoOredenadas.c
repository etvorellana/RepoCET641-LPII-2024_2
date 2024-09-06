#include <stdio.h>
#include <stdlib.h>
#define N 100

/*
    * lista: o array que implementa nossa lista
    * tam: o tamanho ou quantidade de elementos na lista, 
    * chave: chave procurada
    Retorna o índice do elemento do array que tem a chave procurada,
    um valor entre 0 e tam - 1. Caso contrario retorna tam.
*/
int busca(int lista[], int tam, int chave);

/*
    A função inclui um novo elemento chave no final da lista mas somente
    se não estiver repetido.
*lista: o array que implementa alista
*tam: o tamanho ou quantidade de elementos na lista
*cap: a capacidade máxima da lista
*chave: a chave a ser incluída

Retorna verdadeiro (1) se oa chave for incluída e falso (0) caso contrário.
*/
int append(int lista[], int tam, int cap, int chave);


/*
    A função remove um elemento da lista.
*lista: o array que implementa alista
*tam: o tamanho ou quantidade de elementos na lista
*chave: a chave a ser removida
*/
int remove(int lista[], int tam, int chave);



int main(void)
{
    int lista[N] = {0};
    int cap = N,tam = 0;
    for(tam = 0; tam < 50; )
    {
        int alunoId = rand() % 1000;
        if(append(lista,tam,cap,alunoId))
            tam++;
    }


    return 0;
}
