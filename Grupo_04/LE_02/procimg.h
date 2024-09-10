
unsigned char geraGreyPixel(int tipo);
void geraLinhaR(unsigned char lin[640], int tipo);
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel);
void geraImgGreyB_R(unsigned char img[480][640]);
void geraImgGreyW_R(unsigned char img[480][640]);
void geraImgGrey_R(unsigned char img[480][640], int tipo);
int pixelMax_R(unsigned char img[480][640]);
int pixelMin_R(unsigned char img[480][640]);
void somaPorLinhas_R(unsigned char img[480][640], int soma[480]);
void somaPorColunas_R(unsigned char img[480][640], int soma[640]);
int somaPorTotal_R(unsigned char img[480][640], int linha);
int quantosPixelsNaInt_R(unsigned char img[480][640], unsigned char value);
int quantosPixelsAbaixoDeInt_R(unsigned char img[480][640], unsigned char value);
int quantosPixelsAcimaDeInt_R(unsigned char img[480][640], unsigned char value);