#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

#define NLIN 256
#define NCOL 256

int main(void) {
    srand(time(NULL));

    int total = NLIN * NCOL, check;

    //Q1
    imgGray imagemGray = alocaImagemGray(NLIN, NCOL);
    if(imagemGray.img == NULL || imagemGray._img == NULL)
        printf("Q1 - Falha na alocacao\n\n");
    else
        printf("Q1 - Imagem cinza alocada com sucesso\n\n");


    //Q2
    imgRGB imagemRGB = alocaImagemRGB(NLIN, NCOL);
    if(imagemGray.img == NULL || imagemGray._img == NULL)
        printf("Q2 - Falha na alocacao\n\n");
    else
        printf("Q2 - Imagem RGB alocada com sucesso\n\n");


    // Q3
    uchar pixel = 20;
    check = geraImgGrayFull(imagemGray,pixel);

    if(check == 0) 
        printf("Q3 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q3 - A funcao funcionou!\n\n");


    //Q4
    tRGB pixelRGB = {10, 20, 30};
    check = geraImgRGBFull(imagemRGB, pixelRGB);

    if(check == 0) 
        printf("Q4 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q4 - A funcao funcionou!\n\n");


    //Q5
    check = geraImgGrayB(imagemGray);

    if(check == 0) 
        printf("Q5 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q5 - A funcao funcionou!\n\n");


    //Q6
    check = geraImgRGBB(imagemRGB);

    if(check == 0) 
        printf("Q6 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q6 - A funcao funcionou!\n\n");
    

    //Q7
    check = geraImgGrayW(imagemGray);

    if(check == 0) 
        printf("Q7 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q7 - A funcao funcionou!\n\n");


    //Q8
    check = geraImgRGBW(imagemRGB);

    if(check == 0) 
        printf("Q8 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q8 - A funcao funcionou!\n\n");


    //Q9
    check = geraImgGray(imagemGray, 1);

    if(check == 0) 
        printf("Q9 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q9 - A funcao funcionou!\n\n");


    //Q10
    check = geraImgRGB(imagemRGB, 1);

    if(check == 0) 
        printf("Q10 - A funcao falhou!\n\n");
    else if(check == 1)
        printf("Q10 - A funcao funcionou!\n\n");


    //Q11
    geraImgGrayFull(imagemGray,12);
    imagemGray._img[total-1] = 120;
    int maior = pixelGrayMax(imagemGray);
    if(maior != 120) 
        printf("Q11.1 - A funcao falhou!\n");
    else if(maior == 120)
        printf("Q11.1 - A funcao funcionou!\n");
    printf("Maior intensidade da Imagem: %d\n",maior);


    geraImgGrayFull(imagemGray,120);
    imagemGray._img[total-1] = 5;
    int menor = pixelGrayMin(imagemGray);
    if(menor != 5) 
        printf("Q11.2 - A funcao falhou!\n");
    else if(menor == 5)
        printf("Q11.2 - A funcao funcionou!\n");
    printf("Menor intensidade da Imagem: %d\n\n",menor);
    

    //Q12
    tRGB maiorINTEN,menorINTEN;
    tRGB pixelAux = {20, 20, 20};

    geraImgRGBFull(imagemRGB, pixelAux);

    pixelAux.R = 120;
    pixelAux.G = 120;
    pixelAux.B = 120;

    imagemRGB._img[total-1] = pixelAux;

    maiorINTEN = pixelRGBMax(imagemRGB);

    if(maiorINTEN.R != 120 || maiorINTEN.G != 120 || maiorINTEN.B != 120) 
        printf("Q12.1 - A funcao falhou!\n");
    else if(maiorINTEN.R == 120 || maiorINTEN.G == 120 || maiorINTEN.B == 120)
        printf("Q12.1 - A funcao funcionou!\n");
    printf("Maior intensidade da Imagem: (%d, %d, %d)\n",maiorINTEN.R,maiorINTEN.G,maiorINTEN.B);

    geraImgRGBFull(imagemRGB, pixelAux);

    pixelAux.R = 12;
    pixelAux.G = 12;
    pixelAux.B = 12;

    imagemRGB._img[total-1] = pixelAux;

    menorINTEN = pixelRGBMin(imagemRGB);

    if(menorINTEN.R != 12 || menorINTEN.G != 12 || menorINTEN.B != 12) 
        printf("Q12.2 - A funcao falhou!\n");
    else if(menorINTEN.R == 12 || menorINTEN.G == 12 || menorINTEN.B == 12)
        printf("Q12.2 - A funcao funcionou!\n");
    printf("Menor intensidade da Imagem: (%d, %d, %d)\n\n",menorINTEN.R,menorINTEN.G,menorINTEN.B);


    //Q13
    geraImgGrayFull(imagemGray,1);

    int* somaLINHA = somaPorLinhasGray(imagemGray);
    int* somaCOLUNA = somaPorColunasGray(imagemGray);

    int cont = 0;

    for(int i = 0; i < NLIN; i++) {
        if(somaLINHA[i] != NCOL)
            cont++;
    }

    if(cont == 0) 
        printf("Q13.1 - A funcao funcionou!\n");
    else
        printf("Q13.1 - A funcao nao funcionou!\n");

    cont = 0;

    for(int j = 0; j < NCOL; j++){
        if(somaCOLUNA[j] != NLIN)
            cont++;
    }

    if(cont == 0) 
        printf("Q13.2 - A funcao funcionou!\n\n");
    else
        printf("Q13.2 - A funcao nao funcionou!\n\n");


    //Q14 
    pixelAux.R = 1;
    pixelAux.G = 1;
    pixelAux.B = 1;
    geraImgRGBFull(imagemRGB, pixelAux);
    
    tRGB* somLINHA = somaPorLinhasRGB(imagemRGB);
    tRGB* somCOLUNA = somaPorColunasRGB(imagemRGB);

    cont = 0;

    for(int i = 0; i < NLIN; i++) {
        if(somLINHA[i].R != NCOL || somLINHA[i].G != NCOL || somLINHA[i].B != NCOL)
            cont++;
    }

    if(cont == 0) 
        printf("Q14.1 - A funcao funcionou!\n");
    else
        printf("Q14.1 - A funcao nao funcionou!\n");

    cont = 0;

    for(int j = 0; j < NCOL; j++){
        if(somCOLUNA[j].R != NLIN || somCOLUNA[j].G != NLIN || somCOLUNA[j].B != NLIN)
            cont++;
    }

    if(cont == 0) 
        printf("Q14.2 - A funcao funcionou!\n\n");
    else
        printf("Q14.2 - A funcao nao funcionou!\n\n");

    //Q14 ALTERNATIVA
    tRGBInt* somaLINHAALT = somaPorLinhasRGBALTERNATIVA(imagemRGB);
    tRGBInt* somaCOLUNAALT = somaPorColunasRGBALTERNATIVA(imagemRGB);

    cont = 0;

    for(int i = 0; i < NLIN; i++) {
        if(somaLINHAALT[i].R != NCOL || somaLINHAALT[i].G != NCOL || somaLINHAALT[i].B != NCOL)
            cont++;
    }

    if(cont == 0) 
        printf("Q14ALT.1 - A funcao alternativa funcionou!\n");
    else
        printf("Q14ALT.1 - A funcao alternativa nao funcionou!\n");

    cont = 0;

    for(int j = 0; j < NCOL; j++){
        if(somaCOLUNAALT[j].R != NLIN || somaCOLUNAALT[j].G != NLIN || somaCOLUNAALT[j].B != NLIN)
            cont++;
    }

    if(cont == 0) 
        printf("Q14ALT.2 - A funcao alternativa funcionou!\n\n");
    else
        printf("Q14ALT.2 - A funcao alternativa nao funcionou!\n\n");


    //Q15
    geraImgGrayFull(imagemGray,1);

    int somaTOTAL = somaTotalGray(imagemGray);

    if(somaTOTAL == total) 
        printf("Q15 - A funcao funcionou!\n\n");
    else
        printf("Q15 - A funcao nao funcionou!\n\n");


    //Q16
    pixelAux.R = 1;
    pixelAux.G = 1;
    pixelAux.B = 1;
    geraImgRGBFull(imagemRGB, pixelAux);

    tRGB somaTOTALRGB = somaTotalRGB(imagemRGB);

    if(somaTOTALRGB.R == total && somaTOTALRGB.G == total && somaTOTALRGB.B == total) 
        printf("Q16 - A funcao funcionou!\n\n");
    else
        printf("Q16 - A funcao nao funcionou!\n\n");


    //Q16 ALTERNATIVA
    tRGBInt somaTOTALRGBALT = somaTotalRGBALTERNATIVA(imagemRGB);

    if(somaTOTALRGBALT.R == total && somaTOTALRGBALT.G == total && somaTOTALRGBALT.B == total) 
        printf("Q16ALT - A funcao alternativa funcionou!\n\n");
    else
        printf("Q16ALT - A funcao alternativa nao funcionou!\n\n");


    //Q17
    geraImgGrayFull(imagemGray,12);

    int inten = 12;

    int quant = quantosPixelsGrayNaInt(imagemGray,inten);

    if(quant == total)
        printf("Q17 - A funcao funcionou!\n\n");
    else
        printf("Q17 - A funcao nao funcionou!\n\n");


    //Q18
    pixelAux.R = 12;
    pixelAux.G = 12;
    pixelAux.B = 12;
    geraImgRGBFull(imagemRGB, pixelAux);

    tRGB intens;
    intens.R = 12;
    intens.G = 12;
    intens.B = 12;

    quant = quantosPixelsRGBNaInt(imagemRGB,intens);

    if(quant == total)
        printf("Q18 - A funcao funcionou!\n\n");
    else
        printf("Q18 - A funcao nao funcionou!\n\n");

}