#ifndef PROCIMG_H
#define PROCIMG_H

// Definição das dimensões da imagem
#define ALTURA 48  // Altura padrão
#define LARGURA 64 // Largura padrão

//Q01:
unsigned char geraPixelCinza(int tipo);

void geraLinhaR(unsigned char lin[LARGURA], int tipo, int index);
void geraLinha(unsigned char lin[LARGURA], int tipo);

// Função AUX P/ Q02, Q03, Q04
void preencheRecursivo(unsigned char img[ALTURA][LARGURA], unsigned char pixel, int i, int j);

//Q02
void geraImgGreyFull_R(unsigned char img[ALTURA][LARGURA], unsigned char pixel);

//Q03
void geraImgGreyB_R(unsigned char img[ALTURA][LARGURA]);

//Q04
void geraImgGreyW_R(unsigned char img[ALTURA][LARGURA]);

//Q05
void geraImgGrey_R(unsigned char img[ALTURA][LARGURA], int tipo, int i, int j);
void geraImgGrey(unsigned char img[ALTURA][LARGURA], int tipo);

//Q06
int pixelMax_R_aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int valorMax);
int pixelMax_R(unsigned char img[ALTURA][LARGURA]);

//Q07
int pixelMin_R_aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int valorMin);
int pixelMin_R(unsigned char img[ALTURA][LARGURA]);

//Q08
void somaPorLinhas_R_Aux(unsigned char img[ALTURA][LARGURA], int soma[ALTURA], int linha, int coluna, int somaLinha);
void somaPorLinhas_R(unsigned char img[ALTURA][LARGURA], int soma[ALTURA]);

//Q09
void somaPorColunas_R_Aux(unsigned char img[ALTURA][LARGURA], int soma[LARGURA], int linha, int coluna, int somaColuna);
void somaPorColunas_R(unsigned char img[ALTURA][LARGURA], int soma[LARGURA]);

//Q10
int somaPorTotal_R_Aux(unsigned char img[ALTURA][LARGURA], int linha, int coluna, int somaTotal);
int somaPorTotal_R(unsigned char img[ALTURA][LARGURA]);

//Q11
int quantosPixelsNaInt_R_Aux(unsigned char img[ALTURA][LARGURA], unsigned char intensidade, int lin, int col);
int quantosPixelsNaInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade);

//Q12
int quantosPixelsAbaixoDeInt_R_Aux(unsigned char img[ALTURA][LARGURA], unsigned char intensidade, int lin, int col);
int quantosPixelsAbaixoDeInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade);

//Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[ALTURA][LARGURA], unsigned char intensidade);

#endif