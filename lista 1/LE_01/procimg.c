// Implementação das funções

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned char geraGreyPixel(int type)
{
  int valor;
  valor = rand() % 256;

  if (type < 0 && valor >= 128)
    valor = rand() % 128;
  else if (type > 0 && valor < 128)
    valor = 128 + rand() % 128;
  else
    valor = rand() % 256;

  return (unsigned char)valor;
}

void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel)
{
  for (int i = 0; i < 640; i++)
    for (int j = 0; j < 480; j++)
      img[i][j] = pixel;
};

void geraImgGreyB(unsigned char img[640][480])
{
  for (int i = 0; i < 640; i++)
    for (int j = 0; j < 480; j++)
      img[i][j] = 0;
}

void geraImgGreyW(unsigned char img[640][480])
{
  for (int i = 0; i < 640; i++)
    for (int j = 0; j < 480; j++)
      img[i][j] = 255;
}

void drwLin(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel)
{
  int x, y;
  float m, b;

  m = (yB - yA) / (xB - xA); // Calculo da inclinação da reta
  b = yA - m * xA;           // Calcular termo independente

  x = xA < xB ? xA : xB;

  if (xA != xB && yA != yB)
    for (x; x <= (xA > xB ? xA : xB); x++)
    {
      y = (int)m * x + b;
      if (x >= 0 && x < 640 && y >= 0 && y < 480)
        img[x][y] = pixel;
    }
}

int pixelMax(unsigned char img[640][480])
{
  unsigned char x = 0;
  int i, j;
  for (i = 0; i < 640; i++)
  {
    for (j = 0; j < 480; j++)
    {
      if (img[i][j] > x)
      {
        x = img[i][j];
      }
    }
  }
  return x;
}

int pixelMin(unsigned char img[640][480])
{
  unsigned char x = 255;
  int i, j;
  for (i = 0; i < 640; i++)
  {
    for (j = 0; j < 480; j++)
    {
      if (img[i][j] < x)
      {
        x = img[i][j];
      }
    }
  }
  return x;
}

void imgHistogram(unsigned char img[640][480], int hist[255])
{
  for (int i = 0; i < 256; i++)
  {
    hist[i] = 0;
  }

  for (int i = 0; i < 640; i++)
  {
    for (int j = 0; j < 480; j++)
    {
      unsigned char ValPixel = img[i][j];
      hist[ValPixel]++;
    }
  }
}

void pixelMedEDesv(unsigned char img[640][480], float *med, float *desv)
{
  float soma = 0, qtd = 640 * 480, desvAux = 0;
  // calcular media
  for (int i = 0; i < 640; i++)
  {
    for (int j = 0; j < 480; j++)
    {
      soma += img[i][j];
    }
  }
  *med = soma / qtd;

  // calcular desvio padrao
  for (int i = 0; i < 640; i++)
  {
    for (int j = 0; j < 480; j++)
    {
      desvAux += pow((img[i][j] - *med), 2);
    }
  }
  *desv = sqrt(desvAux / qtd);
}

void drwRect(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel)
{
  int x, y;
  y = yB;
  x = xB;
  for (int i = 0; i < 480; i++)
  {
    for (int j = 0; j < 640; j++)
    {
      img[j][i] = 0;
    }
  }

  for (int i = yA; i < 480; i++)
  {
    for (int j = xA; j < 640; j++)
    {
      if (i < y && j < x)
      {
        img[j][i] = pixel;
      }
    }
  }
}

void drwCirc(unsigned char img[640][480], int x, int y, int rad, unsigned char pixel)
{
  for (int i = 0; i < 640; i++)
  {
    for (int j = 0; j < 480; j++)
    {
      if (((j - x) * (j - x) + (i - y) * (i - y) < rad * rad))
      {
        img[i][j] = pixel;
      }
      else
      {
        img[i][j] = 0;
      }
    }
  }
}

void drwTriang(unsigned char img[640][480], int xA, int yA, int xB, int yB, int xC, int yC, unsigned char pixel)
{
  drwLin(img, xA, yA, xB, yB, pixel);
  drwLin(img, xC, yC, xB, yB, pixel);
  drwLin(img, xA, yA, xC, yC, pixel);

  /* Preencher o triangulo */
  // int minX = (xA < xB) ? (xA < xC ? xA : xC) : (xB < xC ? xB : xC);
  // int maxX = (xA > xB) ? (xA > xC ? xA : xC) : (xB > xC ? xB : xC);
  // int minY = (yA < yB) ? (yA < yC ? yA : yC) : (yB < yC ? yB : yC);
  // int maxY = (yA > yB) ? (yA > yC ? yA : yC) : (yB > yC ? yB : yC);

  // for (int y = minY; y <= maxY; y++)
  // {
  //   for (int x = minX; x <= maxX; x++)
  //   {
  //     int w1 = (x - xB) * (yA - yB) - (y - yB) * (xA - xB);
  //     int w2 = (x - xC) * (yB - yC) - (y - yC) * (xB - xC);
  //     int w3 = (x - xA) * (yC - yA) - (y - yA) * (xC - xA);

  //     if ((w1 >= 0 && w2 >= 0 && w3 >= 0) || (w1 <= 0 && w2 <= 0 && w3 <= 0))
  //     {
  //       img[x][y] = pixel;
  //     }
  //   }
  // }
}
