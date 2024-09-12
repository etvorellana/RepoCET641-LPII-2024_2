#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALTURA 48
#define LARGURA 64

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
void geraLinhaR(unsigned char lin[LARGURA], int tipo, int index) {
    if (index >= LARGURA) return; // Condição de parada
    lin[index] = geraPixelCinza(tipo); // Preenche a posição atual com um valor gerado
    geraLinhaR(lin, tipo, index + 1); // Chama a função recursivamente para a próxima posição
}

// Q01: Função para iniciar a recursão
void geraLinha(unsigned char lin[LARGURA], int tipo) {
    geraLinhaR(lin, tipo, 0);
}

// 2A: Função recursiva auxiliar para preencher a imagem
void preencheRecursivo(unsigned char img[ALTURA][LARGURA], unsigned char pixel, int i, int j) {
    if (i >= ALTURA) return;
    if (j >= LARGURA) {
        preencheRecursivo(img, pixel, i + 1, 0);
        return;
    }
    img[i][j] = pixel;
    preencheRecursivo(img, pixel, i, j + 1);
}

// Q02: Funções para inicializar a recursão com a cor desejada
void geraImgGreyFull_R(unsigned char img[ALTURA][LARGURA], unsigned char pixel) {
    preencheRecursivo(img, pixel, 0, 0);
}

// Q03: 0 sendo preto
void geraImgGreyB_R(unsigned char img[ALTURA][LARGURA]) { 
    preencheRecursivo(img, 0, 0, 0);
}

// Q04: 255 sendo branco
void geraImgGreyW_R(unsigned char img[ALTURA][LARGURA]) { 
    preencheRecursivo(img, 255, 0, 0);
}

// Q05: Função recursiva para preencher a imagem com valores aleatórios
void geraImgGrey_R(unsigned char img[ALTURA][LARGURA], int tipo, int i, int j) {
    if (i >= ALTURA) return; // Condição de parada
    if (j >= LARGURA) {
        geraImgGrey_R(img, tipo, i + 1, 0); // Passa para a próxima linha
        return;
    }
    img[i][j] = geraPixelCinza(tipo); // Preenche o pixel atual com um valor gerado
    geraImgGrey_R(img, tipo, i, j + 1); // Chama a função recursivamente para o próximo pixel na linha
}

// Q05: Função para iniciar a recursão
void geraImgGrey(unsigned char img[ALTURA][LARGURA], int tipo) {
    geraImgGrey_R(img, tipo, 0, 0);
}

// Q06 (AUXILIAR): Retorna o pixel de maior intensidade de uma imagem 
int pixelMax_R_aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int valorMax) {
    if (linha == ALTURA) {
        return valorMax; 
    }
    if (coluna == LARGURA) {
        return pixelMax_R_aux(img, linha + 1, 0, valorMax);
    }
    if (img[linha][coluna] > valorMax) {
        valorMax = img[linha][coluna];
    } 
    return pixelMax_R_aux(img, linha, coluna + 1, valorMax);
}

int pixelMax_R(unsigned char img[ALTURA][LARGURA]) {
    return pixelMax_R_aux(img, 0, 0, 0);
}

// Q07 (AUXILIAR): Retorna o pixel de menor intensidade de uma imagem
int pixelMin_R_aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int valorMin) {
    if (linha == ALTURA) {
        return valorMin;
    }
    if (coluna == LARGURA) {
        return pixelMin_R_aux(img, linha + 1, 0, valorMin);
    }
    if (img[linha][coluna] < valorMin) {
        valorMin = img[linha][coluna];
    }
    return pixelMin_R_aux(img, linha, coluna + 1, valorMin);
}

int pixelMin_R(unsigned char img[ALTURA][LARGURA]) {
    return pixelMin_R_aux(img, 0, 0, 255);
}

// Q08: Função auxiliar para somar os elementos das linhas da matriz
void somaPorLinhas_R_Aux(unsigned char img[ALTURA][LARGURA], int soma[ALTURA], int linha, int coluna, int somaLinha) {
    if (linha == ALTURA) return;
    if (coluna == LARGURA) {
        soma[linha] = somaLinha;
        somaPorLinhas_R_Aux(img, soma, linha + 1, 0, 0);
        return;
    }
    somaPorLinhas_R_Aux(img, soma, linha, coluna + 1, somaLinha + img[linha][coluna]);
}

void somaPorLinhas_R(unsigned char img[ALTURA][LARGURA], int soma[ALTURA]) {
    return somaPorLinhas_R_Aux(img, soma, 0, 0, 0);
}

// Q09: Função auxiliar para somar os elementos das colunas da matriz
void somaPorColunas_R_Aux(unsigned char img[ALTURA][LARGURA], int soma[LARGURA], int linha, int coluna, int somaColuna) {
    if (coluna == LARGURA) return;
    if (linha == ALTURA) {
        soma[coluna] = somaColuna;
        somaPorColunas_R_Aux(img, soma, 0, coluna + 1, 0);
        return;
    }
    somaPorColunas_R_Aux(img, soma, linha + 1, coluna, somaColuna + img[linha][coluna]);
}

void somaPorColunas_R(unsigned char img[ALTURA][LARGURA], int soma[LARGURA]) {
    return somaPorColunas_R_Aux(img, soma, 0, 0, 0);
}

// Q10: Função auxiliar para somar os elementos da matriz
int somaPorTotal_R_Aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int somaTotal) {
    if (linha == ALTURA) return somaTotal;
    if (coluna == LARGURA) return somaPorTotal_R_Aux(img, linha + 1, 0, somaTotal);
    return img[linha][coluna] + somaPorTotal_R_Aux(img, linha, coluna + 1, somaTotal);
}

int somaPorTotal_R(unsigned char img[ALTURA][LARGURA]) {
    return somaPorTotal_R_Aux(img, 0, 0, 0);
}

// Q11: Função auxiliar recursiva para contar pixels com uma intensidade específica
int quantosPixelsNaInt_R_Aux(unsigned char img[ALTURA][LARGURA], unsigned char intensidade, int lin, int col) {
    if (lin >= ALTURA) return 0;
    if (col >= LARGURA) return quantosPixelsNaInt_R_Aux(img, intensidade, lin + 1, 0);
    int cont = (img[lin][col] == intensidade) ? 1 : 0;
    return cont + quantosPixelsNaInt_R_Aux(img, intensidade, lin, col + 1);
}

int quantosPixelsNaInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade) {
    return quantosPixelsNaInt_R_Aux(img, intensidade, 0, 0);
}

// Q12: Função auxiliar recursiva para contar pixels com intensidade menor
int quantosPixelsAbaixoDeInt_R_Aux(unsigned char img[ALTURA][LARGURA], unsigned char intensidade, int lin, int col) {
    if (lin >= ALTURA) return 0;
    if (col >= LARGURA) return quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, lin + 1, 0);
    int cont = (img[lin][col] < intensidade) ? 1 : 0;
    return cont + quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, lin, col + 1);
}

int quantosPixelsAbaixoDeInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade) {
    return quantosPixelsAbaixoDeInt_R_Aux(img, intensidade, 0, 0);
}

// Q13: Função recursiva para contar pixels com intensidade maior que a especificada
int quantosPixelsAcimaDeInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade) {
    if (ALTURA == 0 || LARGURA == 0) return 0;
    int contador = 0;
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (img[i][j] > intensidade) contador++;
        }
    }
    return contador;
}