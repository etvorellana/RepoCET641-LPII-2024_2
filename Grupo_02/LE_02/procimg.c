#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float search = -0.5;


// Função para gerar um pixel em tons de cinza com diferentes probabilidades
unsigned char geraPixelCinza(int tipo) {
    int valorAleatorio = rand() % 256; // Gera um valor entre 0 e 255

    if (tipo < 0) {
        // Intensidades mais escuras (0-127) têm maior probabilidade
        if (valorAleatorio < 128) {
            return (unsigned char)(valorAleatorio / 2); // Aumenta a probabilidade de valores menores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else if (tipo > 0) {
        // Intensidades mais claras (128-255) têm maior probabilidade
        if (valorAleatorio >= 128) {
            return (unsigned char)(128 + (valorAleatorio / 2)); // Aumenta a probabilidade de valores maiores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else {
        // Todas as intensidades têm a mesma probabilidade
        return (unsigned char)(valorAleatorio);
    }
}

// Q01: Função recursiva para preencher uma linha com valores aleatórios
void geraLinhaR(unsigned char lin[640], int tipo, int index) {
    if (index >= 640) return; // Condição de parada
    lin[index] = geraPixelCinza(tipo); // Preenche a posição atual com um valor gerado
    geraLinhaR(lin, tipo, index + 1); // Chama a função recursivamente para a próxima posição
}

// Q01: Função para iniciar a recursão
void geraLinha(unsigned char lin[640], int tipo) {
    geraLinhaR(lin, tipo, 0);
}

// 2A: Função recursiva auxiliar para preencher a imagem
void preencheRecursivo(unsigned char img[480][640], unsigned char pixel, int i, int j) {
    if (i >= 480) return;
    if (j >= 640) {
        preencheRecursivo(img, pixel, i + 1, 0);
        return;
    }
    img[i][j] = pixel;
    preencheRecursivo(img, pixel, i, j + 1);
}

// Q02: Funções para inicializar a recursão com a cor desejada
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel) {
    preencheRecursivo(img, pixel, 0, 0);
}

// Q03: 0 sendo preto
void geraImgGreyB_R(unsigned char img[480][640]) { 
    preencheRecursivo(img, 0, 0, 0);
}

// Q04: 255 sendo branco
void geraImgGreyW_R(unsigned char img[480][640]) { 
    preencheRecursivo(img, 255, 0, 0);
}

// Q05: Função recursiva para preencher a imagem com valores aleatórios
void geraImgGrey_R(unsigned char img[480][640], int tipo, int i, int j) {
    if (i >= 480) return; // Condição de parada
    if (j >= 640) {
        geraImgGrey_R(img, tipo, i + 1, 0); // Passa para a próxima linha
        return;
    }
    img[i][j] = geraPixelCinza(tipo); // Preenche o pixel atual com um valor gerado
    geraImgGrey_R(img, tipo, i, j + 1); // Chama a função recursivamente para o próximo pixel na linha
}

// Q05: Função para iniciar a recursão
void geraImgGrey(unsigned char img[480][640], int tipo) {
    geraImgGrey_R(img, tipo, 0, 0);
}

//Q06 (AUXILIAR): Retorna o pixel de maior intensidade de uma imagem 
int pixelMax_R_aux(unsigned char img[480][640], int linha, int coluna, int valorMax) {
    //caso inicial: quando termina de percorrer todas as lnhas, retorna o valorMax
    if (linha == 480) {
        return valorMax; 
    }
    // quando termina de percorrer todas as colunas, passa para a proxima linha e começa da 1a coluna
    if (coluna == 640) {
        return pixelMax_R_aux(img, linha + 1, 0, valorMax);
    }
    // se o pixel atual for maior que o valorMax, atualiza o valorMax
    if (img[linha][coluna] > valorMax) {
        valorMax = img[linha][coluna];
    } 
    // passa para o proximo pixel da mesma linha e proxima coluna
    return pixelMax_R_aux(img, linha, coluna + 1, valorMax);
}

int pixelMax_R(unsigned char img[480][640]) {
    return pixelMax_R_aux(img, 0, 0, 0); //chama a funcao auxiliar começando por [0][0] e valorMax = 0
}


//Q07 (AUXILIAR): Retorna o pixel de menor intensidade de uma imagem
int pixelMin_R_aux(unsigned char img[480][640], int linha, int coluna, int valorMin) {
    if (linha == 480) {
        return valorMin;
    }
    if (coluna == 640) {
        return pixelMin_R_aux(img, linha + 1, 0, valorMin);
    }
    if (img[linha][coluna] < valorMin) {
        valorMin = img[linha][coluna];
    }
    
    return pixelMin_R_aux(img, linha, coluna + 1, valorMin);
}

int pixelMin_R(unsigned char img[480][640]) {
    return pixelMin_R_aux(img, 0, 0, 255);
}


// Q08: Função auxiliar para somar os elementos das linhas da matriz
void somaPorLinhas_R_Aux(unsigned char img[480][640], int soma[480], int linha, int coluna, int somaLinha){

    if(linha == 480){
        return;
    }

    if(coluna == 640){
        soma[linha] = somaLinha;
        somaPorLinhas_R_Aux(img, soma, linha + 1, 0, 0);
        return;
    }

    somaPorLinhas_R_Aux(img, soma, linha, coluna + 1, somaLinha + img[linha][coluna]);
}

void somaPorLinhas_R(unsigned char img[480][640], int soma[480]){
    return somaPorLinhas_R_Aux(img, soma, 0, 0, 0);
}


// Q09: Função auxiliar para somar os elementos das colunas da matriz
void somaPorColunas_R_Aux(unsigned char img[480][640], int soma[640], int linha, int coluna, int somaColuna){

    if(coluna == 640){
        return;
    }

    if(linha == 480){
        soma[coluna] = somaColuna;
        somaPorColunas_R_Aux(img, soma, 0, coluna + 1, 0);
        return;
    }

    somaPorColunas_R_Aux(img, soma, linha + 1, coluna, somaColuna + img[linha][coluna]);
}

void somaPorColunas_R(unsigned char img[480][640], int soma[640]){
    return somaPorColunas_R_Aux(img, soma, 0, 0, 0);
}


// Q10: Função auxiliar para somar os elementos da matriz
int somaPorTotal_R_Aux(unsigned char img[480][640], int linha, int coluna, int somaTotal) {

    if(linha == 480){
        return somaTotal;
    }   

    if(coluna == 640){  
        return somaPorTotal_R_Aux(img, linha + 1, 0, somaTotal);
    }

    return img[linha][coluna] + somaPorTotal_R_Aux(img, linha, coluna + 1, somaTotal);
}

int somaPorTotal_R(unsigned char img[480][640]){
    return somaPorTotal_R_Aux(img, 0, 0, 0);
}


// Q11: Função auxiliar recursiva para contar pixels com uma intensidade específica
int quantosPixelsNaInt_R_Aux(unsigned char img[480][640], unsigned char intensidade, int lin, int col) {
    // Caso base: todas as linhas foram processadas. Quando todas as linhas foram processadas (lin >= 480), a função retorna 0, indicando que não há mais pixels a contar.
    if (lin >= 480) {
        return 0;
    }
    // Se chegou ao final da coluna, passa para a próxima linha
    if (col >= 640) {
        return quantosPixelsNaInt_R_Aux(img, intensidade, lin + 1, 0);
    }
    // Verifica se o pixel atual tem a intensidade especificada
    int cont = (img[lin][col] == intensidade) ? 1 : 0;

    // Chama recursivamente para o próximo pixel na mesma linha
    return cont + quantosPixelsNaInt_R_Aux(img, intensidade, lin, col + 1);
}

int quantosPixelsNaInt_R(unsigned char img[480][640], unsigned char intensidade) {
    return quantosPixelsNaInt_R_Aux(img, intensidade, 0, 0);
}

// Q12: Função auxiliar recursiva para contar pixels com intensidade menor
int quantosPixelsAbaixoDeInt_R_Aux(unsigned char img[480][640], unsigned char intensidade, int lin, int col) {
    // Caso base: todas as linhas foram processadas
    if (lin >= 480) {
        return 0;
    }
    // Se chegou ao final da coluna, passa para a próxima linha
    if (col >= 640) {
        return quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, lin + 1, 0);
    }
    // Verifica se o pixel atual tem intensidade menor que a especificada
    int cont = (img[lin][col] < intensidade) ? 1 : 0;

    // Chama recursivamente para o próximo pixel na mesma linha
    return cont + quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, lin, col + 1);
}

int quantosPixelsAbaixoDeInt_R(unsigned char img[480][640], unsigned char intensidade) {
    return quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, 0, 0);
}

// Q13: Função para contar pixels com intensidade maior que um valor
int quantosPixelsAcimaDeInt_R(unsigned char img[480][640], unsigned char intensidade) {
    // Conta os pixels com intensidade igual à especificada
    int iguais = quantosPixelsNaInt_R(img, intensidade);

    // Conta os pixels com intensidade menor que a especificada
    int abaixo = quantosPixelsAbaixoDeInt_R(img, intensidade);

    // Calcula e retorna a quantidade de pixels com intensidade maior
    return 480 * 640 - (iguais + abaixo);
}

//Q14:
unsigned char pontoEquilibrio(unsigned char img[480][640], unsigned char intt) {

  if(quantosPixelsNaInt_R(img, intt) != 0){

    return intt;
    }

  search = (search >= 0.0) ? search + 0.5 : search - 0.5;
  search *= (-1);

  return pontoEquilibrio(img, intt + (int)search);
}