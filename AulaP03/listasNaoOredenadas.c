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
int append(int lista[], int* tam, int cap, int chave);
/*
    A função remove um elemento da lista.
*lista: o array que implementa alista
*tam: o tamanho ou quantidade de elementos na lista
*chave: a chave a ser removida
*/
int remover(int lista[], int* tam, int chave);
int main(void)
{
    int lista[N] = {0};
    int cap = N,tam = 0;
    for(tam = 0; tam < 50; ){
        int alunoId = rand() % 1000;
        append(lista, &tam, cap, alunoId)
    }
    int pos = rand() % 50;
    int chave = lista[pos];
    if (remover(lista,tam,chave))
        printf("Elemento %d removido\n",chave); 
    else
        printf("Elemento %d não encontrado\n",chave);
    return 0;
}


int busca(int lista[], int tam, int chave)
{
    if(tam == 0)
        return tam;
    if(lista[0] == chave)
        return 0;
    else return 1 + busca(lista + 1, tam - 1, chave);
}

int buscaOrdenada(int lista[], int tam, int chave)
{

}


int buscaBackward(int lista[], int tam, int chave)
{
    int valor;
    if (tam == 0)
        return -1;
    if (lista[tam - 1] == chave)
        return tam - 1;
    return (busca(lista, tam - 1, chave));
}

int append(int lista[], int* tam, int cap, int chave)
{
    if(*tam == cap)
        return 0;
    if(busca(lista,*tam,chave) == *tam)
    {
        lista[*tam] = chave;
        return 1;
    }
    return 0;
}

int remover(int lista[], int* tam, int chave)
{
    if (*tam == 0)
        return 0;
    int pos = busca(lista,*tam,chave);
    if(pos == *tam)
        return 0;
    for(int i = pos; i < *tam - 1; i++)
        lista[i] = lista[i + 1];
    (*tam)--;
    return 1;
}