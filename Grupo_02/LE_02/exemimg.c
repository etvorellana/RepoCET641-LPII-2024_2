#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
// Q01 a Q05
int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    unsigned char img[480][640];

    // Q02: Testa a função geraImgGreyFull_R
    unsigned char pixel = geraPixelCinza(0); // Gera um valor de pixel com probabilidade uniforme
    geraImgGreyFull_R(img, pixel);
    printf("Pixel [0][0] apos geraImgGreyFull_R: %u\n", img[0][0]);
    printf("Pixel [639][479] apos geraImgGreyFull_R: %u\n", img[479][639]);

    // Q03: Testa a função geraImgGreyB_R
    geraImgGreyB_R(img);
    printf("Pixel [0][0] apos geraImgGreyB_R: %u\n", img[0][0]);
    printf("Pixel [639][479] apos geraImgGreyB_R: %u\n", img[479][639]);

    // Q04: Testa a função geraImgGreyW_R
    geraImgGreyW_R(img);
    printf("Pixel [0][0] apos geraImgGreyW_R: %u\n", img[0][0]);
    printf("Pixel [639][479] apos geraImgGreyW_R: %u\n", img[479][639]);

    // Q05: Testa a função geraImgGrey
    int tipo = 1;
    geraImgGrey(img, tipo);
    printf("Pixel [0][0] apos geraImgGrey: %u\n", img[0][0]);
    printf("Pixel [639][479] apos geraImgGrey: %u\n", img[479][639]);

    return 0;
}
*/


/* 
// Q06 e Q07
int main (void) {

    srand(time(NULL));

    unsigned char img[480][640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = rand() % 256;
        }
    }

    int pixel_max = pixelMax_R(img);
    int pixel_min = pixelMin_R(img);

    printf("Pixel de maior intensidade: %d\n", pixel_max);
    printf("Pixel de menor intensidade: %d\n", pixel_min);

    return 0;
}
*/


/*
// Q11 a Q13
int main() {
    // Declara uma imagem com dimensões 480x640
    unsigned char img[480][640];

    // Preenche a imagem com valores de exemplo (aqui, todos os pixels com valor 128)
    for(int i = 0; i < 480; i++) {
        for(int j = 0; j < 640; j++) {
            img[i][j] = 128; // Pode preencher com outros valores ou carregar uma imagem real
        }
    }

    unsigned char intensidade = 128; // Intensidade de exemplo

    // Testa a função para contar pixels com intensidade específica
    int resultado = quantosPixelsNaInt_R(img, intensidade);
    printf("Pixels com intensidade %d: %d\n", intensidade, resultado);

    // Testa a função para contar pixels abaixo de uma intensidade
    resultado = quantosPixelsAbaixoDeInt_R(img, intensidade);
    printf("Pixels com intensidade menor que %d: %d\n", intensidade, resultado);

    // Testa a função para contar pixels acima de uma intensidade
    resultado = quantosPixelsAcimaDeInt_R(img, intensidade);
    printf("Pixels com intensidade maior que %d: %d\n", intensidade, resultado);

    return 0;
}
*/


/*
// Q14
int main() {

unsigned char img[480][640];
int Pmax, Pmin, QntPmax, QntPmin;
float search = -0.5;

  Pmax = pixelMax_R(img);
  Pmin = pixelMin_R(img);
  QntPmax = quantosPixelsNaInt_R(img, Pmax);
  QntPmin = quantosPixelsNaInt_R(img, Pmin);

  unsigned char PE;

  if(search == -0.5)
  PE = ((QntPmax * Pmax) + (QntPmin * Pmin) / (QntPmax + QntPmin));

  pontoEquilibrio(img, PE);

  return 0;
}
*/