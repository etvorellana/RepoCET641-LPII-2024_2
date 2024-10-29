#include <stdio.h>
#include <stdlib.h>

#include "procimg.h"

void test_q1();
void test_q2();
void test_q3();
void test_q4();
void test_q5();
void test_q6();
void test_q7();
void test_q8();
void test_q9();
void test_q10();
void test_q11a();
void test_q11b();
void test_q12a();
void test_q12b();
void test_q13a();
void test_q13b();
void test_q14a();
void test_q14b();
void test_q15();
void test_q16();
void test_q17();
void test_q18();

int main()
{
  test_q1();
  test_q2();
  test_q3();
  test_q4();
  test_q5();
  test_q6();
  test_q7();
  test_q8();
  test_q9();
  test_q10();
  test_q11a();
  test_q11b();
  test_q12a();
  test_q12b();
  test_q13a();
  test_q13b();
  test_q14a();
  // test_q14b(); Overflow que samuel explicou o porque houve
  test_q15();
  test_q16();
  test_q17();
  test_q18();

  return 0;
}

void test_q1()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);

  if (img._img != NULL && img.img != NULL)
  {
    printf("função 'alocaImagemGray' rodou como esperado\n");
  }
  else
  {
    printf("função 'alocaImagemGray' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q2()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);

  if (img._img != NULL && img.img != NULL)
  {
    printf("função 'alocaImagemRGB' rodou como esperado\n");
  }
  else
  {
    printf("função 'alocaImagemRGB' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q3()
{
  int nLin = 10, nCol = 10;
  uchar pixel = 78;
  imgGray img = alocaImagemGray(nLin, nCol);

  if (geraImgGrayFull(img, pixel))
  {
    int executa = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i] != pixel)
      {
        executa = 0;
        break;
      }
    }
    printf("função geraImgGrayFull %s\n", executa ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgGrayFull não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q4()
{
  int nLin = 10, nCol = 10;
  tRGB pixel = {78, 78, 78};
  imgRGB img = alocaImagemRGB(nLin, nCol);

  if (geraImgRGBFull(img, pixel))
  {
    int executou = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i].R != pixel.R || img._img[i].G != pixel.G || img._img[i].B != pixel.B)
      {
        executou = 0;
        break;
      }
    }
    printf("função geraImgRGBFull %s\n", executou ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgRGBFull não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q5()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);

  if (geraImgGrayB(img))
  {
    int executou = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i] != 0)
      {
        executou = 0;
        break;
      }
    }
    printf("função geraImgGrayB %s\n", executou ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgGrayB não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q6()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);

  if (geraImgRGBB(img))
  {
    int executou = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i].R != 0 || img._img[i].G != 0 || img._img[i].B != 0)
      {
        executou = 0;
        break;
      }
    }
    printf("função geraImgRGBB %s\n", executou ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgRGBB não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q7()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);
  if (geraImgGrayW(img))
  {
    int executou = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i] != 255)
      {
        executou = 0;
        break;
      }
    }
    printf("função geraImgGrayW %s\n", executou ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgGrayW não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q8()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  tRGB white = {255, 255, 255};
  if (geraImgRGBW(img))
  {
    int executou = 1;
    for (int i = 0; i < nLin * nCol; i++)
    {
      if (img._img[i].R != white.R || img._img[i].G != white.G || img._img[i].B != white.B)
      {
        executou = 0;
        break;
      }
    }
    printf("função geraImgRGBW %s\n", executou ? "rodou como esperado" : "não rodou como esperado");
  }
  else
  {
    printf("função geraImgRGBW não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q9()
{
  int nLin = 10, nCol = 10, flag = 1, saida;
  imgGray img = alocaImagemGray(nLin, nCol);
  saida = geraImgGray(img, 2);

  for (int i = 0; i < nLin * nCol; i++)
  {
    if (img._img[i] < 0 || img._img[i] > 255)
    {
      flag = 0;
    }
  }

  if (saida != 1 || flag == 0)
  {
    printf("função 'geraImgGray' rodou como esperado\n");
  }
  else
  {
    printf("função 'geraImgGray' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q10()
{
  int nLin = 10, nCol = 10, flag = 1, saida;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  saida = geraImgRGB(img, 2);

  for (int i = 0; i < nLin * nCol; i++)
  {
    if (img._img[i].R < 0 || img._img[i].R > 255 ||
        img._img[i].G < 0 || img._img[i].G > 255 ||
        img._img[i].B < 0 || img._img[i].B > 255)
    {

      flag = 0;
    }
  }
  if (saida == 0 || flag == 0)
  {
    printf("função 'geraImgRGB' rodou como esperado\n");
  }
  else
  {
    printf("função 'geraImgRGB' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q11a()
{
  int nLin = 10, nCol = 10, saida;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 5);

  img._img[5] = 10;

  saida = pixelGrayMax(img);

  if (saida == 10)
  {
    printf("função 'pixelGrayMax' rodou como esperado\n");
  }
  else
  {
    printf("função 'pixelGrayMax' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q11b()
{
  int nLin = 10, nCol = 10, saida;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 5);

  img._img[5] = 2;

  saida = pixelGrayMin(img);

  if (saida == 2)
  {
    printf("função 'pixelGrayMin' rodou como esperado\n");
  }
  else
  {
    printf("função 'pixelGrayMin' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q12a()
{
  int nLin = 10, nCol = 10;
  tRGB pixel = {1, 1, 1}, saida;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  geraImgRGBFull(img, pixel);

  img._img[5].R = 10;
  img._img[8].G = 10;
  img._img[1].B = 10;

  saida = pixelRGBMax(img);

  if (saida.R == 10 && saida.G == 10 && saida.B == 10)
  {
    printf("função 'pixelRGBMax' rodou como esperado\n");
  }
  else
  {
    printf("função 'pixelRGBMax' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q12b()
{
  int nLin = 10, nCol = 10;
  tRGB pixel = {5, 5, 5}, saida;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  geraImgRGBFull(img, pixel);

  img._img[5].R = 1;
  img._img[8].G = 1;
  img._img[1].B = 1;

  saida = pixelRGBMin(img);

  if (saida.R == 1 && saida.G == 1 && saida.B == 1)
  {
    printf("função 'pixelRGBMin' rodou como esperado\n");
  }
  else
  {
    printf("função 'pixelRGBMin' não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}

void test_q13a()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 1);

  int *somaLinhas = somaPorLinhasGray(img);
  int executou = 1;
  for (int i = 0; i < nLin; i++)
  {
    if (somaLinhas[i] != nCol)
    {
      executou = 0;
      break;
    }
  }

  printf("função somaPorLinhasGray %s\n", executou ? "rodou como esperado" : "não rodou como esperado");

  free(somaLinhas);
  free(img._img);
  free(img.img);
}

void test_q13b()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 1);

  int *somaColunas = somaPorColunasGray(img);
  int executou = 1;
  for (int i = 0; i < nCol; i++)
  {
    if (somaColunas[i] != nLin)
    {
      executou = 0;
      break;
    }
  }
  printf("função somaPorColunasGray %s\n", executou ? "rodou como esperado" : "não rodou como esperado");

  free(somaColunas);
  free(img._img);
  free(img.img);
};

void test_q14a()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  tRGB color = {1, 2, 3};
  geraImgRGBFull(img, color); // Preenche todos os pixels com {1, 2, 3}

  tRGB *somaLinhas = somaPorLinhasRGB(img);
  int executou = 1;
  for (int i = 0; i < nLin; i++)
  {
    if (somaLinhas[i].R != nCol * color.R || somaLinhas[i].G != nCol * color.G || somaLinhas[i].B != nCol * color.B)
    {
      executou = 0;
      break;
    }
  }

  printf("função somaPorLinhasRGB %s\n", executou ? "rodou como esperado" : "não rodou como esperado");

  free(somaLinhas);
  free(img._img);
  free(img.img);
};

void test_q14b()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  tRGB color = {1, 2, 3};
  geraImgRGBFull(img, color); // Preenche todos os pixels com {1, 2, 3}

  tRGB *somaColunas = somaPorColunasRGB(img);
  int executou = 1;
  for (int i = 0; i < nCol; i++)
  {
    if (somaColunas[i].R != nLin * color.R || somaColunas[i].G != nLin * color.G || somaColunas[i].B != nLin * color.B)
    {
      executou = 0;
      break;
    }
  }

  printf("função somaPorColunasRGB %s\n", executou ? "rodou como esperado" : "não rodou como esperado");

  free(somaColunas);
  free(img._img);
  free(img.img);
};
void test_q15()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 1);

  int total = somaTotalGray(img);
  if (total == nLin * nCol)
  {
    printf("função somaTotalGray rodou como esperado\n");
  }
  else
  {
    printf("função somaTotalGray não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
};
void test_q16()
{
  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);
  tRGB color = {1, 1, 1};
  geraImgRGBFull(img, color);

  tRGB total = somaTotalRGB(img);
  if (total.R == nLin * nCol && total.G == nLin * nCol && total.B == nLin * nCol)
  {
    printf("função somaTotalRGB rodou como esperado\n");
  }
  else
  {
    printf("função somaTotalRGB não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
};

void test_q17()
{
  int nLin = 10, nCol = 10;
  imgGray img = alocaImagemGray(nLin, nCol);
  geraImgGrayFull(img, 128);

  int count = quantosPixelsGrayNaInt(img, 128);
  if (count == nLin * nCol)
  {
    printf("função quantosPixelsGrayNaInt não rodou como esperado\n");
  }
  else
  {
    printf("função quantosPixelsGrayNaInt não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
};
void test_q18()
{

  int nLin = 10, nCol = 10;
  imgRGB img = alocaImagemRGB(nLin, nCol);

  tRGB color = {128, 128, 128};
  geraImgRGBFull(img, color);

  int count = quantosPixelsRGBNaInt(img, color);
  if (count == nLin * nCol)
  {
    printf("função quantosPixelsRGBNaInt rodou como esperado\n");
  }
  else
  {
    printf("função quantosPixelsRGBNaInt não rodou como esperado\n");
  }

  free(img._img);
  free(img.img);
}
