#include "procimg.c"
//Q1
void geraLinhaR(unsigned char array [], int tipo);
/*
   * Função que preenche um array [640] com valores aleatórios criados pelo geraGreyPixel (utiliza recursividade)
   * Parâmetro:
   * array: array que será preenchido.
   * tipo: determina a probabilidade dos números aleatórios.
*/
unsigned char geraGreyPixel (int tipo);
/*
   * Função que gera números aleatórios de acordo com o tipo inserido pelo uuário
   * Parâmetro:
   * tipo: determina a probabilidade dos números aleatórios.
*/
//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel);
/*
    *Função que preenche uma imagem 640x480 com pixel(escolhido pelo usuário) utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    *pixel: número que será preenchido a imagem.
*/
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna]);
/*
    *Função que preenche uma imagem 640x480 com 0 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
*/
//Q4
void preencheimg(unsigned char img[480][640],int pixel,int i,int j);
void geraImgGreyW_R(unsigned char img[480][640]);
/*
    *Função que preenche uma imagem 640x480 com 255 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
*/
//Q5
void geraImgGrey_R(unsigned char img[480][640],int tipo);
/*
   *Função que utilizando da função geraGreyPixel preenche a imagem com pixels aleatórios. 
   *Parâmetro:
   *img: matriz onde a imagem será preenchida.
   *tipo: determina a probabilidade dos números aleatórios.
*/
//Q6
int pixelMax_R(unsigned char img[linha][coluna]);
int aux_pixelMax_R(unsigned char img[linha][coluna], int row, int col, int maxValue);
/*
  *Função que compara todos os pixels da matriz, para descobrir qual é o maior valor.
  *Parametros:
  *img: matriz onde a imagem será preenchida.
*/
//Q7
int pixelMin_R(unsigned char img[linha][coluna]);
int aux_pixelMin_R(unsigned char img[linha][coluna], int row, int col, int minValue);
/*
  *Função que compara todos os pixels da matriz, para descobrir qual é o menor valor.
  *Parametros:
  *img: matriz onde a imagem será preenchida.
*/
//Q8
void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]);
/*
  *Função que soma os elementos de cada linha da matriz.
  *Parãmetros:
  *img: matriz onde a imagem será preencida.
  *soma: vetor soma por cada linha.
*/
//Q9
void somaPorColunas_R(unsigned char img[linha][coluna], int soma[coluna]);
/*
  *Função que soma os elementos de cada coluna da matriz.
  *Parãmetros:
  *img: matriz onde a imagem será preencida.
  *soma: vetor soma por cada coluna.
*/
//Q10
int somaPorTotal_R(unsigned char img[linha][coluna]);
/* 
  *Realiza e retorna a soma dos elementos da imagem img.
  *Parâmetro:
  * img: matriz onde a imagem será preenchida
*/
//Q11
int quantosPixelsNaInt_R (unsigned char img[linha][coluna], unsigned char inte);
/* 
    *retorna a quantidade de pixels, na imagem img, que possuem uma intensidade 
     específica int.
    *Parâmetros:
      *Img: matriz onde a imagem será preenchida
      *inte:número que vai olhar a frequência da intensidade
*/
//Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int);
int aux_quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int, int row, int col, int soma);
/*
  *Função que compara todos os pixels da matriz para descobrir quantos pixels tem valores menores que o valor recebido no parametro Int, exibindo a quantidade de valores menores que Int.
  *Parametros:
  *img: matriz onde a imagem será preenchida
  *Int: valor recebido e usado como base de comparação, para descobrir qual valor é menor que Int. 
*/
//Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[linha][coluna], unsigned char inteiro);
/*
  *Função que retorna quantos pixels tem valor maior que o valor recebido no parametro inteiro.
  *Parametros:
  *img: matriz onde a imagem será preenchida.
  *inteiro: valor recebido. 
*/
//Q14

unsigned char pontoEquilibrio(unsigned char img[linha][coluna], unsigned char Int);
/*
  *Função que retorna qual pixel está mais próxio da média entre o maior pixel e o menor pixel
  *Parametros:
  *img: matriz onde a imagem será preencida.
  *Int: valor retornado e usado para comparar qual a proximidade da média.
*/


