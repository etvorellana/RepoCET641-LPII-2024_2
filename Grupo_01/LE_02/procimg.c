#include <stdlib.h>
#include <stdio.h>
#include "procimg.h"

#define altura 10
#define largura 10

//ANTERIORES
unsigned char geraGreyPixel(int tipo){
    int i = rand() % 100 + 1;
    if(tipo < 0){
        if(i <= 75){
            return (unsigned char)(rand() % 128);
        }
        else{
            return (unsigned char)(128 + rand() % (255 - 128 + 1));
        }
    }
    else if(tipo > 0){
        if(i<=75){
            return (unsigned char)(128 + rand() % (255 - 128 + 1));
        }
        else{
            return (unsigned char)(rand() % 128);
        }
    }
    else {//if(tipo == 0){
        return (unsigned char)(rand() % 255 + 1);
    }
}

void imgHistogram(unsigned char img[altura][largura], int hist[256]){
    for(int i = 0; i < largura; i++){
        for(int j = 0; j < altura; j++){
            hist[(img[i][j])] += 1;
        }
    }
}

void imgRandom(unsigned char img[altura][largura]){
    for(int i = 0; i < largura; i++){
        for(int j = 0; j < altura; j++){
            img[i][j] = (unsigned char)(rand()%256);
        }
    }
}

void displayImg(unsigned char img[altura][largura]){
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            printf("%3d " , img[y][x]);
        }
        printf("\n");
    }
}

///////Q1
void geraLinhaR(unsigned char lin[largura], int tipo){
    geraLinhaRecursiva(lin, tipo, largura - 1);

    return;
}

void geraLinhaRecursiva(unsigned char lin[largura], int tipo, int n){
    if(n < 0)
        return;

    lin[n] = geraGreyPixel(tipo);
    geraLinhaRecursiva(lin, tipo, n-1);
    return;
}


///////Q2
void geraImgGreyFull_R(unsigned char img[altura][largura], unsigned char pixel){
    geraImgGreyFull_Recursiva(img, pixel, altura - 1, largura - 1);
}

void geraImgGreyFull_Recursiva(unsigned char img[altura][largura], unsigned char pixel, int y, int x){
    
    if(y < 0){
        return;
    }

    if(x < 0){
        geraImgGreyFull_Recursiva(img, pixel, y-1, largura - 1);
        return;
    }

    img[y][x] = pixel;
    geraImgGreyFull_Recursiva(img, pixel, y, x-1);
    return;
}


///////Q3
void geraImgGreyB_R(unsigned char img[altura][largura]){
    geraImgGreyB_Recursiva(img, altura - 1, largura - 1);
}

void geraImgGreyB_Recursiva(unsigned char img[altura][largura], int y, int x){

    if(y < 0){
        return;
    }

    if(x < 0){
        geraImgGreyB_Recursiva(img, y-1, largura - 1);
        return;
    }

    img[y][x] = 0;
    geraImgGreyB_Recursiva(img, y, x-1);
    return;
}


///////Q4
void geraImgGreyW_R(unsigned char img[altura][largura]){
    geraImgGreyW_Recursiva(img, altura - 1, largura - 1);
}

void geraImgGreyW_Recursiva(unsigned char img[altura][largura], int y, int x){

    if(y < 0){
        return;
    }

    if(x < 0){
        geraImgGreyW_Recursiva(img, y-1, largura - 1);
        return;
    }

    img[y][x] = 255;
    geraImgGreyW_Recursiva(img, y, x-1);
    return;
}


///////Q5
void geraImgGrey_R(unsigned char img[altura][largura], int tipo){
    geraImgGrey_Recursiva(img, tipo, altura - 1, largura - 1);
}

void geraImgGrey_Recursiva(unsigned char img[altura][largura], int tipo, int y, int x){
    
    if(y < 0){
        return;
    }

    if(x < 0){
        geraImgGrey_Recursiva(img, tipo, y-1, largura - 1);
        return;
    }

    img[y][x] = geraGreyPixel(tipo);
    geraImgGrey_Recursiva(img, tipo, y, x-1);
    return;
}


///////Q6
int pixelMax_R(unsigned char img[altura][largura]){
    return pixelMax_Recursiva(img, altura - 1, largura - 1);
}

int pixelMax_Recursiva(unsigned char img[altura][largura], int y, int x){
    
    if(x < 0){
        return pixelMax_Recursiva(img, y-1, largura - 1);
    }

    if(y < 0){
        return 0;
    }

    int valor = img[y][x];
    int result = pixelMax_Recursiva(img, y, x-1);
    return (result > valor ? result : valor);
}


///////Q7
int pixelMin_R(unsigned char img[altura][largura]){
    return pixelMin_Recursiva(img, altura - 1, largura - 1);
}

int pixelMin_Recursiva(unsigned char img[altura][largura], int y, int x){
    
    if(x < 0){
        return pixelMin_Recursiva(img, y-1, largura - 1);
    }

    if(y < 0){
        return 256;
    }

    int valor = img[y][x];
    int result = pixelMin_Recursiva(img, y, x-1);
    return (result < valor ? result : valor);
}


///////Q8
void somaPorLinhas_R(unsigned char img[altura][largura], int soma[altura]){
    for(int i = 0; i < altura; i++)
        soma[i] = 0;

    somaPorLinhas_Recursiva(img, soma, altura - 1, largura - 1);
}

void somaPorLinhas_Recursiva(unsigned char img[altura][largura], int soma[altura], int y, int x){
    if(x < 0){
        somaPorLinhas_Recursiva(img, soma, y-1, largura - 1);
        return;
    }

    if(y < 0){
        return;
    }

    soma[y] += img[y][x];
    somaPorLinhas_Recursiva(img, soma, y, x-1);
}


///////Q9
void somaPorColunas_R(unsigned char img[altura][largura], int soma[largura]){
    for(int i = 0; i < largura; i++)
        soma[i] = 0;

    somaPorColunas_Recursiva(img, soma, altura - 1, largura - 1);
}

void somaPorColunas_Recursiva(unsigned char img[altura][largura], int soma[largura], int y, int x){
    
    if(y < 0){
        somaPorColunas_Recursiva(img, soma, altura - 1, x-1);
        return;
    }

    if(x < 0){
        return;
    }
    
    soma[x] += img[y][x];
    somaPorColunas_Recursiva(img, soma, y-1, x);
}


///////Q10
int somaPorTotal_R(unsigned char img[altura][largura]){
    return somaPorTotal_Recursiva(img, altura - 1, largura - 1);    
}

int somaPorTotal_Recursiva(unsigned char img[altura][largura], int y, int x){
    if(x < 0){
        return somaPorTotal_Recursiva(img, y-1, largura - 1);
    }

    if(y < 0){
        return 0;
    }

    int valor = img[y][x];

    return valor + somaPorTotal_Recursiva(img, y, x-1);
}


///////Q11
int quantosPixelsNaInt_R(unsigned char img[altura][largura], unsigned char intensidade){
    return quantosPixelsNaInt_Recursiva(img, intensidade, altura - 1, largura - 1);
}

int quantosPixelsNaInt_Recursiva(unsigned char img[altura][largura], unsigned char intensidade , int y, int x){

    if(x < 0){
        return quantosPixelsNaInt_Recursiva(img, intensidade, y-1, largura - 1);
    }

    if(y < 0){
        return 0;
    }

    int valor = img[y][x];
    if(valor == intensidade)
        return 1 + quantosPixelsNaInt_Recursiva(img, intensidade, y, x-1);

    else
        return quantosPixelsNaInt_Recursiva(img, intensidade, y, x-1);
}


///////Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[altura][largura], unsigned char intensidade){
    return quantosPixelsAbaixoDeInt_Recursiva(img, intensidade, altura - 1, largura - 1);
}

int quantosPixelsAbaixoDeInt_Recursiva(unsigned char img[altura][largura], unsigned char intensidade , int y, int x){
    if(x < 0){
        return quantosPixelsAbaixoDeInt_Recursiva(img, intensidade, y-1, largura - 1);
    }

    if(y < 0){
        return 0;
    }

    int valor = img[y][x];
    if(valor < intensidade)
        return 1 + quantosPixelsAbaixoDeInt_Recursiva(img, intensidade, y, x-1);

    else
        return quantosPixelsAbaixoDeInt_Recursiva(img, intensidade, y, x-1);
}


///////Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[altura][largura], unsigned char intensidade){
    
    int totalPixels = altura * largura;

    int pixelsAbaixo = quantosPixelsAbaixoDeInt_R(img, intensidade);
    int pixelsIgual = quantosPixelsNaInt_R(img, intensidade);

    return totalPixels - (pixelsAbaixo + pixelsIgual);

}
