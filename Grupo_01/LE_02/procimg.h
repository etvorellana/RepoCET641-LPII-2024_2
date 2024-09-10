


//ANTERIORES
unsigned char geraGreyPixel(int tipo);
void imgHistogram(unsigned char img[480][640], int hist[256]);
void imgRandom(unsigned char img[480][640]);

//AUXILIAR
void displayImg(unsigned char img[480][640]);

///////Q1
void geraLinhaR(unsigned char lin[640], int tipo);
void geraLinhaRecursiva(unsigned char lin[640], int tipo, int n);

///////Q2
void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel);
void geraImgGreyFull_Recursiva(unsigned char img[480][640], unsigned char pixel, int y, int x);

///////Q3
void geraImgGreyB_R(unsigned char img[480][640]);
void geraImgGreyB_Recursiva(unsigned char img[480][640], int y, int x);

///////Q4
void geraImgGreyW_R(unsigned char img[480][640]);
void geraImgGreyW_Recursiva(unsigned char img[480][640], int y, int x);

///////Q5
void geraImgGrey_R(unsigned char img[480][640], int tipo);
void geraImgGrey_Recursiva(unsigned char img[480][640], int tipo, int y, int x);

///////Q6
int pixelMax_R(unsigned char img[480][640]);
int pixelMax_Recursiva(unsigned char img[480][640], int y, int x);

///////Q7
int pixelMin_R(unsigned char img[480][640]);
int pixelMin_Recursiva(unsigned char img[480][640], int y, int x);

///////Q8
void somaPorLinhas_R(unsigned char img[480][640], int soma[480]);
void somaPorLinhas_Recursiva(unsigned char img[480][640], int soma[480], int y, int x);

///////Q9
void somaPorColunas_R(unsigned char img[480][640], int soma[640]);
void somaPorColunas_Recursiva(unsigned char img[480][640], int soma[640], int y, int x);

///////Q10
int somaPorTotal_R(unsigned char img[480][640]);
int somaPorTotal_Recursiva(unsigned char img[480][640], int y, int x);

///////Q11
int quantosPixelsNaInt_R(unsigned char img[480][640], unsigned char intensidade);
int quantosPixelsNaInt_Recursiva(unsigned char img[480][640], unsigned char intensidade , int y, int x); 

///////Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[480][640], unsigned char intensidade);
int quantosPixelsAbaixoDeInt_Recursiva(unsigned char img[480][640], unsigned char intensidade , int y, int x); 

///////Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[480][640], unsigned char intensidade);

///////Q14
unsigned char pontoEquilibrio(unsigned char img[480][640], unsigned char intensidade);