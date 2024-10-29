typedef unsigned char uchar;

typedef struct
{
  uchar R, G, B;
} tRGB;

typedef struct
{
  uchar *_img;
  uchar **img;
  int nLin, nCol;
} imgGray;

typedef struct
{
  tRGB *_img;
  tRGB **img;
  int nLin, nCol;
} imgRGB;

struct imagems
{
  imgGray img;
  struct imagens *prox;
};

typedef struct imagens tImagens;

imgGray alocaImagemGray(int nLin, int nCol);          // q1
imgRGB alocaImagemRGB(int nLin, int nCol);            // q2
int geraImgGrayFull(imgGray img, uchar pixel);        // q3
int geraImgRGBFull(imgRGB img, tRGB pixel);           // q4
int geraImgGrayB(imgGray img);                        // q5
int geraImgRGBB(imgRGB img);                          // q6
int geraImgGrayW(imgGray img);                        // q7
int geraImgRGBW(imgRGB img);                          // q8
int geraImgGray(imgGray img, int tipo);               // q9
int geraImgRGB(imgRGB img, int tipo);                 // q10
int pixelGrayMax(imgGray img);                        // q11 a
int pixelGrayMin(imgGray img);                        // q11 b
tRGB pixelRGBMax(imgRGB img);                         // q12 a
tRGB pixelRGBMin(imgRGB img);                         // q12 b
int *somaPorLinhasGray(imgGray img);                  // q13 a
int *somaPorColunasGray(imgGray img);                 // q13 b
tRGB *somaPorLinhasRGB(imgRGB img);                   // q14 a
tRGB *somaPorColunasRGB(imgRGB img);                  // q14 b
int somaTotalGray(imgGray img);                       // q15
tRGB somaTotalRGB(imgRGB img);                        // q16
int quantosPixelsGrayNaInt(imgGray img, uchar inten); // q17
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten);    // q18