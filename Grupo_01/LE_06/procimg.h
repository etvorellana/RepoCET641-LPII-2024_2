#include <stdlib.h>

//STRUCTS/ TYPEDEFS:

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

//STRUCT ALTERNATIVA
typedef struct{
    int R, G, B;
}tRGBInt;


typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

//AUX
unsigned char geraGreyPixel(int tipo);

//Q1
imgGray alocaImagemGray(int nLin, int nCol);

//Q2
imgRGB alocaImagemRGB(int nLin, int nCol);

//Q3
int geraImgGrayFull(imgGray img, uchar pixel);

//Q4
int geraImgRGBFull(imgRGB img, tRGB pixel);

//Q5
int geraImgGrayB(imgGray img);

//Q6
int geraImgRGBB(imgRGB img);

//Q7
int geraImgGrayW(imgGray img);

//Q8
int geraImgRGBW(imgRGB img);

//Q9
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
int* somaPorColunasGray(imgGray img);

//Q14
tRGB* somaPorLinhasRGB(imgRGB img);
tRGB* somaPorColunasRGB(imgRGB img);

tRGBInt* somaPorLinhasRGBALTERNATIVA(imgRGB img);
tRGBInt* somaPorColunasRGBALTERNATIVA(imgRGB img);

//Q15
int somaTotalGray(imgGray img);

//Q16
tRGB somaTotalRGB(imgRGB img);

tRGBInt somaTotalRGBALTERNATIVA(imgRGB img);

//Q17
int quantosPixelsGrayNaInt(imgGray img, uchar inten);

//Q18
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten);