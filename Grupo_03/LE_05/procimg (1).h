#include "procimg.c"

//Função free imgGray
void liberaImagemGray(imgGray img);
/*
   *Função que dá free em qualquer img que recebeu alocaImagemGray
   *SÓ FUNCIONA COM O ".IMG" DENTRO DO STRUCT
   *Parâmetros: 
   *img: matriz bidimensional a ser desalocada
*/

//Função free imgRGB
void liberaImagemRGB(imgRGB img);
/*
   *Função que dá free em qualquer img que recebeu alocaImagemRGB
   *SÓ FUNCIONA COM O ".IMG" DENTRO DO STRUCT
   *Parâmetros: 
   *img: matriz bidimensional a ser desalocada
*/

//Q1
imgGray alocaImagemGray(int nLin,int nCol);
/*
    *Função que aloca imagem em tons de cinza
    *Parâmetros:  
    *nLin: quantidade de linhas da matriz
    *nCol: quantidade de colunas da matriz  
    *Retorno:
    *Uma struct com a imagem alocado ou ponteiros nulos em caso de falha 
*/

//Q2
imgRGB  alocaImagemRGB(int nLin,int nCol);
/*
    *Função que aloca imagem colorida
    *Parâmetros:
    *nLin: quantidade de linhas da matriz
    *nCol: quantidade de colunas da matriz
    *Retorno:
    *Uma struct com a imagem alocado ou ponteiros nulos em caso de falha
*/

//Q3
int geraImgGrayFull(imgGray img,uchar pixel);
/*
    *Função que preenche todos os pixels com o valor de pixel 
    *Parâmetros:
    *img: imagem já alocada
    *pixel: valor que preencherá a imagem
    *Retorno:
    *True(1) se funcionar corretamente,False(0) se houver algum erro
*/
//Q4
int geraImgRGBFull(imgRGB img,tRGB pixel);
/*
    *Função que preenche todos os pixels com o valor de pixel 
    *Parâmetros:
    *img: imagem já alocada previamente 
    *pixel: valor da cor RGB para preencher todos os pixels da imagem.
    *Retorno:
    *True(1) se funcionar corretamente,False(0) se houver algum erro
*/
//Q5 
int geraImgGrayB(imgGray img);
/*
    *Função que preenche todos os pixels com 0
    *Parâmetro:
    *img: Imagem já alocada previamente
    *Retorno:
    *True(1) se funcionar corretamente,False(0)d se houver algum erro
*/
//Q6
int geraImgRGBB(imgRGB img);

//Q7
int geraImgGrayW(imgGray img);

//Q8
int geraImgRGBW(imgRGB img);

//Q9
unsigned char geraPixelGrey(int tipo);
int geraImgGray(imgGray img, int tipo);

//Q10
int geraImgRGB(imgRGB img, int tipo);

//Q11

int pixelGrayMax(imgGray img);
int pixelGrayMin(imgGray img);

//Q12

tRGB pixelRGBMax(imgRGB img);
tRGB pixelRGBMin(imgRGB img);

//Q13
int* somaPorLinhasGray(imgGray img);
/*
  *Função que soma os elementos das linhas da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array inteiro somaL (A soma de cada linha)
*/
int* somaPorColunasGray(imgGray img);
/*
  *Função que soma os elementos das colunas da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array inteiro somaC (A soma de cada coluna)
*/

//Q14
tRGB* somaPorLinhasRGB(imgRGB img);
/*
  *Função que soma os elementos R, G e B das linhas da matriz RGB
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array do tipo tRGB linhas (A soma de cada linha)
*/
tRGB* somaPorColunasRGB(imgRGB img);
/*
  *Função que soma os elementos R, G e B das colunas da matriz RGB
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array do tipo tRGB colunas (A soma de cada coluna)
*/

//Q15
int somaTotalGray(imgGray img);
/*
  *Função que soma todos os elementos da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno
  *somaT15 do tipo inteiro (que é a soma de todos os elementos)
*/

//Q16
tRGB somaTotalRGB (imgRGB img);
/*
  *Função que soma todos os elementos da imagem RGB em cada canal (R, G, B)
  * Parâmetro:
  * img: imagem RGB já alocada previamente
  * Retorno:
  * somaT16 do tipo tRGB que armazena a soma total de cada canal
*/

//Q17
int quantosPixelsGrayNaInt(imgGray img, uchar inten);
/*
  *Conta quantos pixels de determinada intensidade têm na imagem gray
  *Parâmetros:
  *img: imagem gray já alocada previamente (utilizada de forma unidimensional)
  *inten: uma intensidade pré-estabelecida
  *Retorno:
  *pixelsG: total de pixels iguais a inten na imagem
*/

//Q18
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten);
/*
  *Conta quantos pixels de determinada intensidade têm na imagem RGB
  *Parâmetros:
  *img: imagem RGB já alocada previamente (utilizada de forma unidimensional)
  *inten: uma intensidade pré-estabelecida em cada canal
  *Retorno:
  *pixelsRGB: total de pixels iguais a a inten na imagem (as intensidades dos 3 canais têm 
   que ser iguais as pré-estabelecidas para contabilizar o pixel)
*/
