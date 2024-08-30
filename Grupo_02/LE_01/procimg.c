#include "procimg.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// 1: Função para gerar um pixel em tons de cinza com diferentes probabilidades
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

// 2: Função para preencher todos os pixels de uma imagem com um valor dado
void preencheImgCinza(unsigned char img[640][480], unsigned char pixel) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = pixel;
        }
    }
}

// 3: Função para preencher todos os pixels de uma imagem com o valor 0 (preto)
void preencheImgPreto(unsigned char img[640][480]) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = 0;
        }
    }
}

// 4: Função para preencher todos os pixels de uma imagem com o valor 255 (branco)
void preencheImgBranco(unsigned char img[640][480]) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = 255;
        }
    }
}

// 5: Função que desenha uma reta dentro da imagem (Algoritmo de Bresenham)
void drwLin(unsigned char img[largura][altura], int xA, int yA, int xB, int yB, unsigned char pixel){
    int dx = abs(xB - xA);
    int dy = abs(yB - yA);
    int sx = (xA < xB) ? 1 : -1;
    int sy = (yA < yB) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        if (xA >= 0 && xA < largura && yA >= 0 && yA < altura) {
            img[xA][yA] = pixel;
        }

        if (xA == xB && yA == yB) break;

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            xA += sx;
        }
        if (e2 < dx) {
            err += dx;
            yA += sy;
        }
    }
}

// 6: Função que desenha uma área retangular dentro da imagem
void drwRect(unsigned char img[largura][altura], int x, int y, int larg, int alt, unsigned char pixel){
    for (int i = x; i < x + larg && i < largura; i++) {
        for (int j = y; j < y + alt && j < altura; j++) {
            img[i][j] = pixel;
        }
    }
}

// 7: Função para desenhar um círculo na imagem
void drwCirc(unsigned char img[altura][largura], int x, int y, int rad, unsigned char pixel) {

    switch(pixel){

        case 1:
            printf("\x1b[31m");
        break;

        case 2:
            printf("\x1b[32m");
        break;

        case 3:
            printf("\x1b[33m");
        break;

        case 4:
            printf("\x1b[34m");
        break;

        case 5:
            printf("\x1b[35m");
        break;

        case 6:
            printf("\x1b[36m");
        break;

        case 7:
            printf("\x1b[37m");
        break;

    }

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if ((((j - x) * (j - x)) + ((i - y) * (i - y))) <= (rad * rad)) {
                img[i][j] = 7;
                printf("\x1b[40m%u", img[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


// 9: Função para encontrar a maior intensidade de pixel na imagem
int pixelMax(unsigned char img[640][480]) {
    int max = img[0][0]; // Inicializa o máximo com o primeiro pixel para coparar

    // for vai percorrer toda a matriz/imagem
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            // Se o pixel atual for maior que o máximo, atualiza o máximo 
            if (img[i][j] > max) {
                max = img[i][j];
            }
        }
    }
    return max;
}

// 10: Função para encontrar a menor intensidade de pixel na imagem
int pixelMin(unsigned char img[640][480]) {
    int min = img[0][0]; // Inicializa o mínimo com o primeiro pixel

    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            if (img[i][j] < min) {
                min = img[i][j]; // Atualiza o mínimo se encontrar um valor menor
            }
        }
    }

    return min;
}



// 11: Função para calcular a média e o desvio padrão
void calculardadosimagem(unsigned char img[largura][altura], double *media, double *desvioPadrao) {
    // Total de pixels na imagem
    int totalPixels = largura * altura;

    // Variáveis para acumular a soma dos valores dos pixels e a soma dos quadrados dos valores dos pixels
    double soma = 0;
    double somaquadrados = 0;

    // Percorre cada pixel da imagem
    for (int i = 0; i < altura; i++) { // i representa a linha
        for (int j = 0; j < largura; j++) { // j representa a coluna
            unsigned char pixel = img[i][j]; // Obtém o valor do pixel na posição [i][j]
            soma += pixel; // Acumula o valor do pixel
            somaquadrados += pixel * pixel; // Acumula o quadrado do valor do pixel
        }
    }

    // Calcula a média dos valores dos pixels
    *media = soma / totalPixels;

    // Calcula a média dos quadrados dos valores dos pixels
    double mediaquadrados = somaquadrados / totalPixels;

    // Calcula a variância e o desvio padrão
    double variancia = mediaquadrados - (*media * *media);
    *desvioPadrao = sqrt(variancia);
}

// 12: Função para gerar o histograma de cores
void imgHistogram(unsigned char img[largura][altura], int hist[256]) {
    // Inicializa o histograma com zeros
  // Desta forma o histograma é retornado na forma de um array de inteiros com 256 posições
    for (int i = 0; i < 256; i++) {
        hist[i] = 0;
    }

    // Percorre cada pixel da imagem
    for (int i = 0; i < altura; i++) { // i representa a linha
        for (int j = 0; j < largura; j++) { // j representa a coluna
            // Incrementa o contador correspondente ao valor de intensidade do pixel
            hist[img[i][j]]++;
        }
    }
}