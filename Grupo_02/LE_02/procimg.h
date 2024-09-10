#ifndef PROCIMG_H
#define PROCIMG_H

//Q01:
unsigned char geraPixelCinza(int tipo);

void geraLinhaR(unsigned char lin[640], int tipo, int index);
void geraLinha(unsigned char lin[640], int tipo);

// FUNÇÃO AUX P/ Q02, Q03, Q04
void preencheRecursivo(unsigned char img[480][640], unsigned char pixel, int i, int j);

//Q02
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel);

//Q03
void geraImgGreyB_R(unsigned char img[480][640]);

//Q04
void geraImgGreyW_R(unsigned char img[480][640]);

//Q05
void geraImgGrey_R(unsigned char img[480][640], int tipo, int i, int j);
void geraImgGrey(unsigned char img[480][640], int tipo);

//Q06
int pixelMax_R_aux(unsigned char img[480][640], int linha, int coluna, int valorMax);
int pixelMax_R(unsigned char img[480][640]);

//Q07
int pixelMin_R_aux(unsigned char img[480][640], int linha, int coluna, int valorMin);
int pixelMin_R(unsigned char img[480][640]);

//Q08
void somaPorLinhas_R_Aux(unsigned char img[480][640], int soma[480], int linha, int coluna, int somaLinha);
void somaPorLinhas_R(unsigned char img[480][640], int soma[480]);

//Q09
void somaPorColunas_R_Aux(unsigned char img[480][640], int soma[640], int linha, int coluna, int somaColuna);
void somaPorColunas_R(unsigned char img[480][640], int soma[640]);

//Q10
int somaPorTotal_R_Aux(unsigned char img[480][640], int linha, int coluna, int somaTotal);
int somaPorTotal_R(unsigned char img[480][640]);

//Q11
int quantosPixelsNaInt_R_Aux(unsigned char img[480][640], unsigned char intensidade, int lin, int col);
int quantosPixelsNaInt_R(unsigned char img[480][640], unsigned char intensidade);

//Q12
int quantosPixelsAbaixoDeInt_R_Aux(unsigned char img[480][640], unsigned char intensidade, int lin, int col);
int quantosPixelsAbaixoDeInt_R(unsigned char img[480][640], unsigned char intensidade);

//Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[480][640], unsigned char intensidade);

//Q14
unsigned char pontoEquilibrio(unsigned char img[480][640], unsigned char intt);

#endif