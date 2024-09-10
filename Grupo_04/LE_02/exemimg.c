#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "procimg.h"

int main(void)
{
  // ########## Exercicios 1 ##########
  // srand(time(NULL));
  // int type;
  // unsigned char lin[640] = {0};

  // printf("Qual tipo? 1, 0 ou -1\n");
  // scanf("%i", &type);

  // geraLinhaR(lin, type);

  // for (int i = 0; i < 640; i++)
  //   printf(" %d ", lin[i]);

  // ########## Exercicios 2 ##########
  // unsigned char lin[480][640] = {0};
  // unsigned char pixel;

  // printf("Qual o valor do pixel? (0 - 255)\n");
  // scanf("%i", &pixel);

  // geraImgGreyFull_R(lin, pixel);

  // int count = 0;
  // for (int i = 0; i < 480; i++)
  //   for (int j = 0; j < 640; j++)
  //     if (lin[i][j] == pixel)
  //       count++;

  // printf("%d foi repetido %d vezes\n", pixel, count);
  // return 0;

  // ########## Exercicios 3 e 4 ##########
  // unsigned char lin[480][640];

  // geraImgGreyB_R(lin);
  // geraImgGreyW_R(lin);

  // int count = 0;
  // for (int i = 0; i < 480; i++)
  //   for (int j = 0; j < 640; j++)
  //     if (lin[i][j] == 0 || lin[i][j] == 255)
  //       count++;

  // printf("%d foi repetido %d vezes\n", 0, count);

  // ########## Exercicios 5 ##########
  // unsigned char lin[480][640];
  // int tipo;

  // printf("Qual tipo? 1, 0 ou -1\n");
  // scanf("%i", &tipo);

  // geraImgGrey_R(lin, tipo);

  // int count = 0;
  // for (int i = 0; i < 480; i++)
  //   for (int j = 0; j < 640; j++)
  //     if (lin[i][j] != 0)
  //       count++;

  // printf("%d foi repetido %d vezes\n", 0, count);

  // ##########Exercicios 6##########
  // unsigned char img[480][640] = {0};

  // geraImgGrey_R(img, 0);

  // int maiorIntensidade = pixelMax_R(img);

  // printf("O pixel com maior intensidade é %d", 0, maiorIntensidade);

  // ##########Exercicios 7##########
  // unsigned char img[480][640] = {0};

  // geraImgGrey_R(img, 0);

  // int menorInten = pixelMin_R(img);

  // printf("O pixel com menor intensidade é %d", 0, menorInten);

  // ########## Exercicios 8 e 9 ##########
  // unsigned char lin[480][640];
  // int soma[480] = {0};

  // geraImgGrey_R(lin, 0);

  // somaPorLinhas_R(lin, soma);
  // somaPorColunas_R(lin, soma);

  // int count = 0;
  // for (int i = 0; i < 480; i++)
  //   printf("Linha %d = %d\n", i + 1, soma[i]);

  // ########## Exercicios 10 ##########
  // unsigned char img[480][640];

  // geraImgGrey_R(img, 0);

  // int somaTotal = somaPorTotal_R(img, 0);

  // printf("A soma total dos pixels da imagem é: %d\n", somaTotal);

  // ########## Exercicios 11 ##########
  // unsigned char img[480][640];
  // int inten;

  // geraImgGrey_R(img, 0);

  // printf("Qual intensidade busca? (0 - 255)?");
  // scanf("%i", inten);

  // int qtd = quantosPixelsNaInt_R(img, inten);

  // printf("A intensidade %d ocorre %d vezes\n", inten, qtd);

  // ########## Exercicios 12 ##########
  // unsigned char img[480][640];
  // int inten;

  // geraImgGrey_R(img, 0);

  // printf("Qual intensidade busca? (0 - 255)?");
  // scanf("%i", inten);

  // int qtd = quantosPixelsAbaixoDeInt_R(img, inten);

  // printf("Os valores abaixo da intensidade %d ocorre %d vezes\n", inten, qtd);

  // ########## Exercicios 13 ##########
  // unsigned char img[480][640];
  // int inten;

  // geraImgGrey_R(img, 0);

  // printf("Qual intensidade busca? (0 - 255)?");
  // scanf("%i", inten);

  // int qtd = quantosPixelsAcimaDeInt_R(img, inten);

  // printf("Os valores Acima da intensidade %d ocorre %d vezes\n", inten, qtd);

  return 0;
}