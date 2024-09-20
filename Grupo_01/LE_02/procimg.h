#define altura 10
#define largura 10

//ANTERIORES
unsigned char geraGreyPixel(int tipo);
void imgHistogram(unsigned char img[altura][largura], int hist[256]);
void imgRandom(unsigned char img[altura][largura]);

//AUXILIAR
void displayImg(unsigned char img[altura][largura]);

///////Q1
void geraLinhaR(unsigned char lin[largura], int tipo);
void geraLinhaRecursiva(unsigned char lin[largura], int tipo, int n);

///////Q2
void geraImgGreyFull_R(unsigned char img[altura][largura], unsigned char pixel);
void geraImgGreyFull_Recursiva(unsigned char img[altura][largura], unsigned char pixel, int y, int x);

///////Q3
void geraImgGreyB_R(unsigned char img[altura][largura]);
void geraImgGreyB_Recursiva(unsigned char img[altura][largura], int y, int x);

///////Q4
void geraImgGreyW_R(unsigned char img[altura][largura]);
void geraImgGreyW_Recursiva(unsigned char img[altura][largura], int y, int x);

///////Q5
void geraImgGrey_R(unsigned char img[altura][largura], int tipo);
void geraImgGrey_Recursiva(unsigned char img[altura][largura], int tipo, int y, int x);

///////Q6
int pixelMax_R(unsigned char img[altura][largura]);
int pixelMax_Recursiva(unsigned char img[altura][largura], int y, int x);

///////Q7
int pixelMin_R(unsigned char img[altura][largura]);
int pixelMin_Recursiva(unsigned char img[altura][largura], int y, int x);

///////Q8
void somaPorLinhas_R(unsigned char img[altura][largura], int soma[altura]);
void somaPorLinhas_Recursiva(unsigned char img[altura][largura], int soma[altura], int y, int x);

///////Q9
void somaPorColunas_R(unsigned char img[altura][largura], int soma[largura]);
void somaPorColunas_Recursiva(unsigned char img[altura][largura], int soma[largura], int y, int x);

///////Q10
int somaPorTotal_R(unsigned char img[altura][largura]);
int somaPorTotal_Recursiva(unsigned char img[altura][largura], int y, int x);

///////Q11
int quantosPixelsNaInt_R(unsigned char img[altura][largura], unsigned char intensidade);
int quantosPixelsNaInt_Recursiva(unsigned char img[altura][largura], unsigned char intensidade , int y, int x); 

///////Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[altura][largura], unsigned char intensidade);
int quantosPixelsAbaixoDeInt_Recursiva(unsigned char img[altura][largura], unsigned char intensidade , int y, int x); 

///////Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[altura][largura], unsigned char intensidade);

///////Q14
unsigned char pontoEquilibrio(unsigned char img[altura][largura], unsigned char intensidade);