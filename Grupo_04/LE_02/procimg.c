#include <stdio.h>
#include <stdlib.h>

#define HEIGTH 75
#define WIDTH 100

// Q1
unsigned char geraGreyPixel(int tipo)
{
  int valor;
  valor = rand() % 256;

  if (tipo < 0 && valor >= 128)
    valor = rand() % 128;
  else if (tipo > 0 && valor < 128)
    valor = 128 + rand() % 128;
  else
    valor = rand() % 256;

  return (unsigned char)valor;
}
// Aux
int preencherArrayRandomly(unsigned char lin[640], int length, int tipo)
{
  if (length == 0)
    return 0;

  int currentPixel = geraGreyPixel(tipo);
  lin[length - 1] = currentPixel;

  return preencherArrayRandomly(lin, length - 1, tipo);
}

// Aux
int preencherMatrizRandomly(unsigned char matriz[480][640], int altura, int larg, int tipo)
{
  if (altura == 0)
  {
    return 0;
  }

  preencherArrayRandomly(matriz[altura - 1], larg, tipo);

  return preencherMatrizRandomly(matriz, altura - 1, larg, tipo);
}

// Aux
int preencherArray(unsigned char lin[640], int length, int pixel)
{
  if (length == 0)
    return 0;

  lin[length - 1] = pixel;

  return preencherArray(lin, length - 1, pixel);
}

// Aux
int preencherMatriz(unsigned char matriz[480][640], int altura, int larg, int pixel)
{
  if (altura == 0)
  {
    return 0;
  }

  preencherArray(matriz[altura - 1], larg, pixel);

  return preencherMatriz(matriz, altura - 1, larg, pixel);
}
// Q1
void geraLinhaR(unsigned char lin[640], int tipo)
{
  preencherArrayRandomly(lin, 640, tipo);
}

// Q2
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel)
{
  preencherMatriz(img, 480, 640, pixel);
}

// Q3
void geraImgGreyB_R(unsigned char img[480][640])
{
  geraImgGreyFull_R(img, 0);
}

// Q4
void geraImgGreyW_R(unsigned char img[480][640])
{
  geraImgGreyFull_R(img, 255);
}
// Q5
void geraImgGrey_R(unsigned char img[480][640], int tipo)
{
  preencherMatrizRandomly(img, 480, 640, tipo);
}

// Q6
int pixelMax_Aux(unsigned char img[HEIGTH][WIDTH], int linha, int coluna, int currentValue)
{
  if (linha == HEIGTH)
  {
    return currentValue;
  }

  if (img[linha][coluna] > currentValue)
  {
    currentValue = img[linha][coluna];
  }

  if (coluna < WIDTH - 1)
  {
    return pixelMax_Aux(img, linha, coluna + 1, currentValue);
  }
  else
  {
    return pixelMax_Aux(img, linha + 1, 0, currentValue);
  }
}

int pixelMax_R(unsigned char img[HEIGTH][WIDTH])
{
  return pixelMax_Aux(img, 0, 0, 0);
}

// Q7
int pixelMin_Aux(unsigned char img[HEIGTH][WIDTH], int linha, int coluna, int currentValue)
{
  if (linha == HEIGTH)
  {
    return currentValue;
  }

  if (img[linha][coluna] < currentValue)
  {
    currentValue = img[linha][coluna];
  }

  if (coluna < WIDTH - 1)
  {
    return pixelMin_Aux(img, linha, coluna + 1, currentValue);
  }
  else
  {
    return pixelMin_Aux(img, linha + 1, 0, currentValue);
  }
}

int pixelMin_R(unsigned char img[HEIGTH][WIDTH])
{
  return pixelMin_Aux(img, 0, 0, 255);
}

// Q8
void somaPorLinhas_RAux(unsigned char img[HEIGTH][WIDTH], int soma[HEIGTH], int linha, int coluna)
{
  if (linha >= HEIGTH)
  {
    return;
  }

  soma[linha] += img[linha][coluna];

  if (coluna < WIDTH - 1)
  {
    somaPorLinhas_RAux(img, soma, linha, coluna + 1);
  }
  else
  {
    somaPorLinhas_RAux(img, soma, linha + 1, 0);
  }
}

void somaPorLinhas_R(unsigned char img[HEIGTH][WIDTH], int soma[HEIGTH])
{
  for (int i = 0; i < HEIGTH; i++)
    for (int j = 0; j < WIDTH; j++)
      img[i][j] = 1;
  somaPorLinhas_RAux(img, soma, 0, 0);
}

// Q9
void somaPorColunas_RAux(unsigned char img[HEIGTH][WIDTH], int soma[WIDTH], int linha, int coluna)
{
  if (coluna >= WIDTH)
  {
    return;
  }

  soma[coluna] += img[linha][coluna];
  if (linha < HEIGTH - 1)
  {
    somaPorColunas_RAux(img, soma, linha + 1, coluna);
  }
  else
  {
    somaPorColunas_RAux(img, soma, 0, coluna + 1);
  }
}

void somaPorColunas_R(unsigned char img[HEIGTH][WIDTH], int soma[WIDTH])
{

  for (int i = 0; i < HEIGTH; i++)
    for (int j = 0; j < WIDTH; j++)
      img[i][j] = 1;

  somaPorColunas_RAux(img, soma, 0, 0);
}

int auxSomaTotal(int somaLinha[HEIGTH], int linha, int currentValue)
{
  if (linha == 0)
    return currentValue;

  currentValue += somaLinha[linha - 1];

  return auxSomaTotal(somaLinha, linha - 1, currentValue);
}

// Q10
int somaPorTotal_R(unsigned char img[HEIGTH][WIDTH])
{
  int somaLinha[HEIGTH] = {0};
  somaPorLinhas_R(img, somaLinha);

  return auxSomaTotal(somaLinha, HEIGTH, 0);
}

int pixelsNumber = 0; // Variavel global aplicavel a 11;
int i, j;             // Variavel global aplicavel a 11;

// Q11
int quantosPixelsNaInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value)
{
  if ((i + j) == HEIGTH + WIDTH)
    return pixelsNumber;
  if (img[i][j] == value)
    pixelsNumber++;
  j++;
  if (j > WIDTH)
  {
    j = 0;
    i++;
  }
  quantosPixelsNaInt_R(img, value);
}
int pixelsAbaixo = 0; // Variavel global aplicavel a 12;
int x = 0, y = 0;     // Variavel global aplicavel a 12;

// Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value)
{
  if ((x + y) + 2 == WIDTH + HEIGTH)
    return pixelsAbaixo;

  if (img[x][y] < value)
    pixelsAbaixo++;

  y++;

  if (y >= WIDTH)
  {
    y = 0;
    x++;
  }

  quantosPixelsAbaixoDeInt_R(img, value);
}

// Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value)
{
  int abaixo = quantosPixelsAbaixoDeInt_R(img, value);
  int iguais = quantosPixelsNaInt_R(img, value);
  printf("\nabaixo == %i", abaixo);
  printf("\niguais == %i", iguais);
  return (HEIGTH * WIDTH) - (abaixo + iguais);
}