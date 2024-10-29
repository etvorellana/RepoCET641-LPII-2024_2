#include <stdio.h>
#include <stdlib.h>

#include "procimg.h"

// Questão 1
imgGray alocaImagemGray(int nLin, int nCol)
{
  imgGray picture;
  picture._img = (uchar *)malloc(nLin * nCol * sizeof(uchar));
  picture.img = (uchar **)malloc(nLin * sizeof(uchar *));

  if (picture._img == NULL || picture.img == NULL)
  {
    if (picture._img == NULL)
      free(picture._img);
    picture.img = NULL;
    picture._img = NULL;
    return picture;
  }

  for (int i = 0; i < nLin; i++)
  {
    picture.img[i] = &picture._img[i * nCol];
  }

  picture.nLin = nLin;
  picture.nCol = nCol;
  return picture;
}

// Questão 2
imgRGB alocaImagemRGB(int nLin, int nCol)
{
  imgRGB picture;
  picture._img = (tRGB *)malloc(nLin * nCol * sizeof(tRGB));
  picture.img = (tRGB **)malloc(nLin * sizeof(tRGB *));

  if (picture._img == NULL || picture.img == NULL)
  {
    if (picture._img == NULL)
      free(picture._img);
    picture.img = NULL;
    picture._img = NULL;
    return picture;
  }

  for (int i = 0; i < nLin; i++)
  {
    picture.img[i] = &picture._img[i * nCol];
  }

  picture.nLin = nLin;
  picture.nCol = nCol;
  return picture;
}

// Questão 3
int geraImgGrayFull(imgGray img, uchar pixel)
{
  if (img.img == NULL)
    return 0;

  for (int i = 0; i < img.nLin * img.nCol; i++)
  {
    img._img[i] = pixel;
  }

  return 1;
}

// Questão 4
int geraImgRGBFull(imgRGB img, tRGB pixel)
{
  if (img.img == NULL)
    return 0;

  for (int i = 0; i < img.nLin * img.nCol; i++)
  {
    img._img[i] = pixel;
  }
  return 1;
}
// Questão 5
int geraImgGrayB(imgGray img)
{
  return geraImgGrayFull(img, 0);
}

// Questão 6
int geraImgRGBB(imgRGB img)
{
  tRGB preto = {0, 0, 0};
  return geraImgRGBFull(img, preto);
}

// Questão 7
int geraImgGrayW(imgGray img)
{
  return geraImgGrayFull(img, 255);
}

// Questão 8
int geraImgRGBW(imgRGB img)
{
  tRGB branco = {255, 255, 255};
  return geraImgRGBFull(img, branco);
}

// funcao geraPixelGrey feita na outra lista usada para as proximas questoes
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

// Questão 9
int geraImgGray(imgGray img, int tipo)
{
  if (img.img == NULL)
    return 0;

  for (int i = 0; i < img.nLin * img.nCol; i++)
  {
    img._img[i] = geraGreyPixel(tipo);
  }

  return 1;
}

// Questao 10
int geraImgRGB(imgRGB img, int tipo)
{
  if (img.img == NULL)
    return 0;

  for (int i = 0; i < img.nLin * img.nCol; i++)
  {
    tRGB pixel;
    pixel.R = geraGreyPixel(tipo);
    pixel.G = geraGreyPixel(tipo);
    pixel.B = geraGreyPixel(tipo);
    img._img[i] = pixel;
  }

  return 1;
}

// Questao 11a
int pixelGrayMax(imgGray img)
{
  uchar max = img._img[0];
  for (int i = 1; i < img.nLin * img.nCol; i++)
  {
    if (img._img[i] > max)
    {
      max = img._img[i];
    }
  }

  return max;
}

// Questao 11b
int pixelGrayMin(imgGray img)
{
  uchar min = img._img[0];
  for (int i = 1; i < img.nLin * img.nCol; i++)
  {
    if (img._img[i] < min)
    {
      min = img._img[i];
    }
  }

  return min;
}

// Questao 12a
tRGB pixelRGBMax(imgRGB img)
{
  tRGB max;
  max.R = img._img[0].R;
  max.G = img._img[0].G;
  max.B = img._img[0].B;

  for (int i = 1; i < img.nLin * img.nCol; i++)
  {
    if (img._img[i].R > max.R)
    {
      max.R = img._img[i].R;
    }
    if (img._img[i].G > max.G)
    {
      max.G = img._img[i].G;
    }
    if (img._img[i].B > max.B)
    {
      max.B = img._img[i].B;
    }
  }

  return max;
}

// Questao 12b
tRGB pixelRGBMin(imgRGB img)
{
  tRGB min;
  min.R = img._img[0].R;
  min.G = img._img[0].G;
  min.B = img._img[0].B;

  for (int i = 1; i < img.nLin * img.nCol; i++)
  {
    if (img._img[i].R < min.R)
    {
      min.R = img._img[i].R;
    }
    if (img._img[i].G < min.G)
    {
      min.G = img._img[i].G;
    }
    if (img._img[i].B < min.B)
    {
      min.B = img._img[i].B;
    }
  }

  return min;
}

// Questão 13 a
int *somaPorLinhasGray(imgGray img)
{
  int *soma;

  soma = (int *)calloc(img.nLin, sizeof(int));

  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      soma[i] += img.img[i][j];
    }
  }
  return soma;
}
// Questão 13 b
int *somaPorColunasGray(imgGray img)
{
  int *soma;

  soma = (int *)malloc(img.nCol * sizeof(int));

  for (int i = 0; i < img.nCol; i++)
  {
    soma[i] = 0;
  }
  for (int i = 0; i < img.nCol; i++)
  {
    for (int j = 0; j < img.nLin; j++)
    {
      soma[i] += img.img[j][i];
    }
  }
  return soma;
}

// Questão 14 a
tRGB *somaPorLinhasRGB(imgRGB img)
{

  tRGB *soma;

  soma = malloc(sizeof(tRGB));

  for (int i = 0; i < img.nLin; i++)
  {
    soma[i].R = 0;
    soma[i].G = 0;
    soma[i].B = 0;
  }
  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      soma[i].R += img.img[i][j].R;
      soma[i].G += img.img[i][j].G;
      soma[i].B += img.img[i][j].B;
    }
  }
  return soma;
}

// Questão 14 b
tRGB *somaPorColunasRGB(imgRGB img)
{

  tRGB *soma;

  soma = malloc(img.nCol * sizeof(tRGB));

  for (int i = 0; i < img.nCol; i++)
  {
    soma[i].R = 0;
    soma[i].G = 0;
    soma[i].B = 0;
  }
  for (int j = 0; j < img.nCol; j++)
  {
    for (int i = 0; j < img.nLin; i++)
    {
      soma[i].R += img.img[i][j].R;
      soma[i].G += img.img[i][j].G;
      soma[i].B += img.img[i][j].B;
    }
  }
  return soma;
}

// Questão 15
int somaTotalGray(imgGray img)
{

  int soma = 0;

  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      soma += img.img[i][j];
    }
  }
  return soma;
}

// Questão 16
tRGB somaTotalRGB(imgRGB img)
{
  tRGB soma = {0, 0, 0};

  if (img.img == NULL)
    return soma;

  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      soma.R += img.img[i][j].R;
      soma.G += img.img[i][j].G;
      soma.B += img.img[i][j].B;
    }
  }

  return soma;
}

// Questão 17
int quantosPixelsGrayNaInt(imgGray img, uchar inten)
{
  int count = 0;
  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      if (img.img[i][j] == inten)
      {
        count++;
      }
    }
  }
  return count;
}

// Questão 18
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten)
{
  int count = 0;
  for (int i = 0; i < img.nLin; i++)
  {
    for (int j = 0; j < img.nCol; j++)
    {
      if (img.img[i][j].R == inten.R &&
          img.img[i][j].G == inten.G &&
          img.img[i][j].B == inten.B)
      {
        count++;
      }
    }
  }
  return count;
}
