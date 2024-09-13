

#define HEIGTH 75 // USADO EM 6, 7, 8, 9, 10, 11, 12, 13
#define WIDTH 100 // USADO EM 6, 7, 8, 9, 10, 11, 12, 13

unsigned char geraGreyPixel(int tipo);
void geraLinhaR(unsigned char lin[640], int tipo);
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel);
void geraImgGreyB_R(unsigned char img[480][640]);
void geraImgGreyW_R(unsigned char img[480][640]);
void geraImgGrey_R(unsigned char img[480][640], int tipo);
int pixelMax_R(unsigned char img[HEIGTH][WIDTH]);
int pixelMin_R(unsigned char img[HEIGTH][WIDTH]);
void somaPorLinhas_R(unsigned char img[HEIGTH][WIDTH], int soma[HEIGTH]);
void somaPorColunas_R(unsigned char img[HEIGTH][WIDTH], int soma[WIDTH]);
int somaPorTotal_R(unsigned char img[HEIGTH][WIDTH]);
int quantosPixelsNaInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value);
int quantosPixelsAbaixoDeInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value);
int quantosPixelsAcimaDeInt_R(unsigned char img[HEIGTH][WIDTH], unsigned char value);