#include <stdio.h>
#include <stdlib.h>
#include "procimg.h"

// AUX
unsigned char geraGreyPixel(int tipo) {
    int prct = rand () % 100 + 1;

    if (tipo<0) {
        if (prct<=75) {
            return rand() % 129; 
        }
        else {
            return rand() % (256 - 128) + 128;
        }
    }
    
    else if (tipo>0) {
        if (prct<=75) {
            return rand() % (256 - 128) + 128; 
        }
        else {
            return rand() % 129; 
        }
    }
    
    else {
        return rand() % 256;
    }
}


// Q1
imgGray alocaImagemGray(int nLin, int nCol) {
    imgGray img1D;
    img1D.nLin = nLin;
    img1D.nCol = nCol;
    img1D._img = NULL;
    img1D.img = NULL;

    img1D._img = (uchar*)calloc(nLin * nCol, sizeof(uchar));
    if (img1D._img == NULL) {
        return img1D; 
    }

    img1D.img = (uchar**)malloc(nLin * sizeof(uchar*));
    if (img1D.img == NULL) {
        free(img1D._img); 
        img1D._img = NULL;
        return img1D;
    }

    for (int i = 0; i < nLin; i++) {
        img1D.img[i] = &img1D._img[i * nCol];
    }

    return img1D;
}


// Q2
imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img1D;
    img1D.nLin = nLin;
    img1D.nCol = nCol;
    img1D._img = NULL;
    img1D.img = NULL;

    img1D._img = (tRGB*)calloc(nLin * nCol,sizeof(tRGB));
    if(img1D._img == NULL) {
        return img1D;
    }

    img1D.img = (tRGB**)calloc(nLin,sizeof(tRGB*));
    if (img1D.img == NULL) {
        free(img1D._img);
        img1D._img = NULL;
        return img1D;
    }

    for(int i = 0; i < nLin; i++) {        
        img1D.img[i] = &img1D._img[i * nCol]; 
    }

    return img1D;
}


// Q3
int geraImgGrayFull(imgGray img, uchar pixel) {
    int iTotal = img.nLin * img.nCol;

    for (int i = 0; i < iTotal; i++) {
        img._img[i] = pixel;
    }

    for (int i = 0; i < iTotal; i++) {
        if (img._img[i] != pixel) {
            return 0; 
        }
    }
    
    return 1; 
}


// Q4
int geraImgRGBFull(imgRGB img, tRGB pixel) {
    int iTotal = img.nLin * img.nCol;

    for(int i = 0; i < iTotal; i++) {
        img._img[i].R = pixel.R;
        img._img[i].G = pixel.G;
        img._img[i].B = pixel.B;
    }

    for (int i = 0; i < iTotal; i++) {
        if ((img._img[i].R != pixel.R) || (img._img[i].G != pixel.G) || (img._img[i].B != pixel.B)) {
            return 0; 
        }
    }

    return 1;
}


// Q5
int geraImgGrayB(imgGray img) {
    int iTotal = img.nLin * img.nCol;

    for (int i = 0; i < iTotal; i++) {
        img._img[i] = 0;
    }

    for (int i = 0; i < iTotal; i++) {
        if (img._img[i] != 0) {
            return 0; 
        }
    }
    
    return 1; 
}


// Q6
int geraImgRGBB(imgRGB img) {
    int iTotal = img.nLin * img.nCol;

    for(int i = 0; i < iTotal; i++) {
        img._img[i].R = 0;
        img._img[i].G = 0;
        img._img[i].B = 0;
    }

    for (int i = 0; i < iTotal; i++) {
        if ((img._img[i].R != 0) || (img._img[i].G != 0) || (img._img[i].B != 0)) {
            return 0; 
        }
    }

    return 1;
}


// Q7
int geraImgGrayW(imgGray img) {
    int iTotal = img.nLin * img.nCol;

    for (int i = 0; i < iTotal; i++) {
        img._img[i] = 255;
    }

    for (int i = 0; i < iTotal; i++) {
        if (img._img[i] != 255) {
            return 0; 
        }
    }
    
    return 1; 
}


// Q8
int geraImgRGBW(imgRGB img) {
    int iTotal = img.nLin * img.nCol;

    for(int i = 0; i < iTotal; i++) {
        img._img[i].R = 255;
        img._img[i].G = 255;
        img._img[i].B = 255;
    }

    for (int i = 0; i < iTotal; i++) {
        if ((img._img[i].R != 255) || (img._img[i].G != 255) || (img._img[i].B != 255)) {
            return 0; 
        }
    }

    return 1;
}


// Q9
int geraImgGray(imgGray img, int tipo) {
    int iTotal = img.nLin * img.nCol;
    uchar* aux = (uchar*)calloc(img.nLin*img.nCol,sizeof(uchar));

    if (aux == NULL) {
        return 0;
    }

    for(int i = 0; i < iTotal; i++) {
        aux[i] = geraGreyPixel(tipo);
        img._img[i] = aux[i];
    }

    for(int j = 0; j < iTotal; j++) {
        if (aux[j] != img._img[j]) {
            free(aux);
            return 0;
        }
    }

    free(aux);

    return 1;
}


// Q10
int geraImgRGB(imgRGB img, int tipo) {
    int iTotal = img.nLin * img.nCol;
    tRGB* aux = (tRGB*)calloc(iTotal, sizeof(tRGB));

    if (aux == NULL) {
        return 0;
    }

    for (int i = 0; i < iTotal; i++) {
        aux[i].R = geraGreyPixel(tipo);
        aux[i].G = geraGreyPixel(tipo);
        aux[i].B = geraGreyPixel(tipo);

        img._img[i].R = aux[i].R;
        img._img[i].G = aux[i].G;
        img._img[i].B = aux[i].B;
    }

    for (int j = 0; j < iTotal; j++) {
        if (img._img[j].R != aux[j].R || img._img[j].G != aux[j].G || img._img[j].B != aux[j].B) {
            free(aux);
            return 0;
        }
    }

    free(aux);
    return 1;
}


// Q11
int pixelGrayMax(imgGray img) {
    int maiorINTEN = img.img[0][0];
    int I = img.nLin;
    int J = img.nCol; 

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            if(maiorINTEN < img.img[i][j]) {
                maiorINTEN = img.img[i][j];
            }
        }
    }
    return maiorINTEN;
} 

int pixelGrayMin(imgGray img) {
    int MenorINTEN = img.img[0][0];
    int I = img.nLin;
    int J = img.nCol; 

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            if(MenorINTEN > img.img[i][j]) {
                MenorINTEN = img.img[i][j];
            }
        }
    }
    return MenorINTEN;
}


// Q12
tRGB pixelRGBMax(imgRGB img) {
    tRGB maiorINTEN;
    maiorINTEN.R = img.img[0][0].R;
    maiorINTEN.G = img.img[0][0].G;
    maiorINTEN.B = img.img[0][0].B;
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            if(maiorINTEN.R < img.img[i][j].R) {
                maiorINTEN.R = img.img[i][j].R;
            }
            if(maiorINTEN.G < img.img[i][j].G) {
                maiorINTEN.G = img.img[i][j].G;
            }
            if(maiorINTEN.B < img.img[i][j].B) {
                maiorINTEN.B = img.img[i][j].B;
            }
        }
    }

    return maiorINTEN;
}

tRGB pixelRGBMin(imgRGB img) {
    tRGB menorINTEN;
    menorINTEN.R = img.img[0][0].R;
    menorINTEN.G = img.img[0][0].G;
    menorINTEN.B = img.img[0][0].B;
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            if(menorINTEN.R > img.img[i][j].R) {
                menorINTEN.R = img.img[i][j].R;
            }
            if(menorINTEN.G > img.img[i][j].G) {
                menorINTEN.G = img.img[i][j].G;
            }
            if(menorINTEN.B > img.img[i][j].B) {
                menorINTEN.B = img.img[i][j].B;
            }
        }
    }

    return menorINTEN;
}


// Q13
int* somaPorLinhasGray(imgGray img) {
    int* somaLINHA = (int*)calloc(img.nLin,sizeof(int));
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaLINHA[i] += img.img[i][j];
        }
    }
    return somaLINHA;
}

int* somaPorColunasGray(imgGray img) {
    int* somaCOLUNA = (int*)calloc(img.nCol,sizeof(int));
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaCOLUNA[j] += img.img[i][j];
        }
    }
    return somaCOLUNA;
}


// Q14
tRGB* somaPorLinhasRGB(imgRGB img) {
    int I = img.nLin;
    int J = img.nCol;
    tRGB* somaLINHA = (tRGB*)calloc(I,sizeof(tRGB));

    for (int i  = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaLINHA[i].R += img.img[i][j].R;
            somaLINHA[i].G += img.img[i][j].G;
            somaLINHA[i].B += img.img[i][j].B;
        }
    }
    return somaLINHA;
}

tRGB* somaPorColunasRGB(imgRGB img) {
    int I = img.nLin;
    int J = img.nCol;
    tRGB* somaCOLUNA = (tRGB*)calloc(J,sizeof(tRGB));

    for (int i  = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaCOLUNA[j].R += img.img[i][j].R;
            somaCOLUNA[j].G += img.img[i][j].G;
            somaCOLUNA[j].B += img.img[i][j].B;
        }
    }
    return somaCOLUNA;
}

//Q15 ALTERNATIVA
tRGBInt* somaPorLinhasRGBALTERNATIVA(imgRGB img) {
    int I = img.nLin;
    int J = img.nCol;
    tRGBInt* somaLINHA = (tRGBInt*)calloc(I,sizeof(tRGBInt));

    for (int i  = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaLINHA[i].R += img.img[i][j].R;
            somaLINHA[i].G += img.img[i][j].G;
            somaLINHA[i].B += img.img[i][j].B;
        }
    }
    return somaLINHA;
}

tRGBInt* somaPorColunasRGBALTERNATIVA(imgRGB img) {
    int I = img.nLin;
    int J = img.nCol;
    tRGBInt* somaCOLUNA = (tRGBInt*)calloc(J,sizeof(tRGBInt));

    for (int i  = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaCOLUNA[j].R += img.img[i][j].R;
            somaCOLUNA[j].G += img.img[i][j].G;
            somaCOLUNA[j].B += img.img[i][j].B;
        }
    }
    return somaCOLUNA;
}


// Q15
int somaTotalGray(imgGray img) {
    int somaTOTAL = 0;
    int TOT = img.nLin * img.nCol;

    for(int i = 0; i<TOT;i++) {
        somaTOTAL += img._img[i];
    }

    return somaTOTAL;
}


// Q16
tRGB somaTotalRGB(imgRGB img) {
    int I = img.nLin * img.nCol;
    tRGB somaTOTAL;

    somaTOTAL.R = 0;
    somaTOTAL.G = 0;
    somaTOTAL.B = 0;

    for (int i  = 0; i < I; i++) {
        somaTOTAL.R += img._img[i].R;
        somaTOTAL.G += img._img[i].G;
        somaTOTAL.B += img._img[i].B;
    }
    return somaTOTAL;
}

// Q16 ALTERNATIVA
tRGBInt somaTotalRGBALTERNATIVA(imgRGB img) {
    int I = img.nLin * img.nCol;
    tRGBInt somaTOTAL;

    somaTOTAL.R = 0;
    somaTOTAL.G = 0;
    somaTOTAL.B = 0;

    for (int i  = 0; i < I; i++) {
        somaTOTAL.R += img._img[i].R;
        somaTOTAL.G += img._img[i].G;
        somaTOTAL.B += img._img[i].B;
    }
    return somaTOTAL;
}


// Q17
int quantosPixelsGrayNaInt(imgGray img, uchar inten) {
    int quantPIXEL = 0;
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            if(img.img[i][j] == inten)
                quantPIXEL ++;
        }
    }

    return quantPIXEL;
}


// Q18
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten) {
    int quantPIXEL = 0;
    int I = img.nLin;
    int J = img.nCol;

    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            if((img.img[i][j].R == inten.R) && (img.img[i][j].G == inten.G) && (img.img[i][j].B == inten.B)) {
                quantPIXEL++;
            } 
        }
    }

    return quantPIXEL;
}