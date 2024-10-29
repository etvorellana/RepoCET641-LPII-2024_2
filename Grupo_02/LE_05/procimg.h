#ifndef PROCIMG_H
#define PROCIMG_H

// #include <procimg.c>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef unsigned char uchar;

// Estrutura de um pixel em RGB
typedef struct { 
    uchar R, G, B;
} tRGB;

// Estrutura de uma imagem em tons de cinza
typedef struct {
    uchar *_img; //ponteiro para um array unidimen que armazena os pixels da imagem em um único bloco de memória
    uchar **img; // ponteiro para um array de ponteiros que apontam para o início de cada linha da imagem. Matriz.
    int nLin, nCol;
} imgGray;

// Estrutura de uma imagem em RGB
typedef struct {
    tRGB *_img; // cada pixel é um tRGB e contem 3 componentes: R, G e B.
    tRGB **img;
    int nLin, nCol;
} imgRGB;

// // Estrutura para armazenar somas que ultrapassam o valor 255
// typedef struct {
//     int R, G, B;
// } tRGB_int;

struct imagens {
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;

void freeImagemGray(imgGray *picture);
void freeImagemRGB(imgRGB *picture);

// Q01: Função que aloca uma imagem em tons de cinza
imgGray alocaImagemGray(int nLin, int nCol);

// Q02: Função que aloca uma imagem em RGB
imgRGB alocaImagemRGB(int nLin, int nCol);

// Q03: Função que preenche uma imagem em tons de cinza com um valor de pixel
int geraImgGrayFull(imgGray picture, uchar pixel);

// Q04: Função que preenche uma imagem em RGB com um valor de pixel
int geraImgRGBFull(imgRGB img, tRGB pixel);

// Q05: Preenche a imagem em tons de cinza com o valor 0 (preto)
int geraImgGrayB(imgGray img);

// Q06: Preenche a imagem em RGB com o valor (0, 0, 0) (preto)
int geraImgRGBB(imgRGB img);

// Q07: Preenche a imagem em tons de cinza com o valor 255 (branco)
int geraImgGrayW(imgGray img);

// Q08: Preenche a imagem em RGB com o valor (255, 255, 255) (branco)
int geraImgRGBW(imgRGB img);

// Q09: Preenche a imagem em tons de cinza com valores aleatórios
int geraImgGray(imgGray img, int tipo);

// Q10: Preenche a imagem em RGB com valores aleatórios
int geraImgRGB(imgRGB img, int tipo);

// Q11: 
// Função para encontrar o pixel de maior intensidade em uma imagem cinza
int pixelGrayMax(imgGray img);
// Função para encontrar o pixel de menor intensidade em uma imagem cinza
int pixelGrayMin(imgGray img);

// Q12: Retorna a maior e menor intensidade de pixel em uma imagem RGB
tRGB pixelRGBMax(imgRGB img);
tRGB pixelRGBMin(imgRGB img);

// Q13: Retorna a soma dos elementos de cda linha da imagem.
int* somaPorLinhasGray(imgGray img);
int* somaPorColunasGray(imgGray img);

// Q14: Retorna a soma dos elementos de cada linha e coluna em uma imagem
tRGB* somaPorLinhasRGB(imgRGB img);
tRGB* somaPorColunasRGB(imgRGB img);

// Q15: Retorna a soma total dos elementos de uma imagem.
int somaTotalGray(imgGray img);

// Q16: Retorna a soma total dos elementos de uma imagem por canal
tRGB somaTotalRGB(imgRGB img);

// Q17: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em tons de cinza
int quantosPixelsGrayNaInt(imgGray img, uchar inten);

// Q18: Função para contar quantos pixels possuem uma intensidade específica em uma imagem RGB
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten);


#endif