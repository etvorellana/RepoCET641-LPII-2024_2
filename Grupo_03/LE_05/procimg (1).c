#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char uchar;

typedef struct
{
    uchar *_img;
    uchar **img;
    int nLin, nCol;

} imgGray;

typedef struct
{
    uchar R, G, B;
} tRGB;

typedef struct
{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
} imgRGB;

struct imagens
{
    imgGray img;
    struct imagens *prox;
};
typedef struct imagens tImagens;

// Q1
imgGray alocaImagemGray(int nLin, int nCol)
{
    imgGray img;
    img.nLin = nLin;
    img.nCol = nCol;

    // Aloca para um ponteiro de ponteiros
    img._img = (uchar*) malloc (nLin*nCol*sizeof(uchar));
    if (img._img == NULL) {
        img.img = NULL;
        return img; // Retorna a estrutura com ponteiros NULL
    }
    img.img = (uchar**) malloc (nLin*sizeof(uchar*));
    if (img.img == NULL) {
        free(img._img);
        img._img = NULL;
        return img;
    }
    for (int i = 0; i < nLin; i++) {
        img.img[i] = img._img + i*nCol;
    }
    return img;
}
// Q2
imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img;
    img.nLin = nLin;
    img.nCol = nCol;

    // Aloca para um ponteiro de ponteiros
    img._img = (tRGB*) malloc (nLin*nCol*sizeof(tRGB));
    if (img._img == NULL) {
        img.img = NULL;
        return img; // Retorna a estrutura com ponteiros NULL
    }
    img.img = (tRGB**) malloc (nLin*sizeof(tRGB*));
    if (img.img == NULL) {
        free(img._img);
        img._img = NULL;
        return img;
    }
    for (int i = 0; i < nLin; i++) {
        img.img[i] = img._img + i*nCol;
    }

    return img;
}

// Q3
int geraImgGrayFull(imgGray img, uchar pixel)
{
    // Verifica se a imagem foi alocada corretamente
    if (img.img == NULL || img.nLin<= 0 || img.nCol<=0)
    {
        return false; // Retorna False (0) se img é NULL
    }

    // Percorre todos os pixels da imagem e os preenche com o valor dado
    for (int i = 0; i < img.nLin; i++)
    {
        for (int j = 0; j < img.nCol; j++)
        {
            img.img[i][j] = pixel; // Preenche o pixel com o valor
        }
    }

    return true; // Retorna True (1) se tudo ocorreu bem
}
// Q4
int geraImgRGBFull(imgRGB img, tRGB pixel)
{
    // Verifica se a imagem foi previamente alocada
    if (img.img == NULL)
    {
        return 0; // Retorna False se a imagem não foi alocada
    }

    // Itera sobre cada pixel e preenche com o valor do pixel fornecido
    for (int i = 0; i < img.nLin; i++)
    {
        if (img.img[i] == NULL || img.nLin<= 0 || img.nCol<=0)
        {
            return 0; // Retorna False se alguma linha não foi alocada corretamente
        }
        for (int j = 0; j < img.nCol; j++)
        {
            img.img[i][j] = pixel;
        }
    }

    return 1; // Retorna True se o preenchimento for bem-sucedido
}
// Q5
int geraImgGrayB(imgGray img)
{
    // Verifica se a imagem foi alocada corretamente
    if (img.img == NULL || img.nLin<=0 || img.nCol<=0)
    {
        return false; // Retorna False (0) se img é NULL
    }

    // Percorre todos os pixels da imagem e os preenche com o valor dado
    for (int i = 0; i < img.nLin; i++)
    {
        for (int j = 0; j < img.nCol; j++)
        {
            img.img[i][j] = 0; // Preenche o pixel com o valor
        }
    }

    return true; // Retorna True (1) se tudo ocorreu bem
}
// Q6
int geraImgRGBB(imgRGB img)
{
    tRGB pixel;
    pixel.R = 0;
    pixel.G = 0;
    pixel.B = 0;
    return geraImgRGBFull(img, pixel);
}
// Q7
int geraImgGrayW(imgGray img)
{
    return geraImgGrayFull(img, 255);
}
// Q8
int geraImgRGBW(imgRGB img)
{
    tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;
    return geraImgRGBFull(img, pixel);
}

unsigned char geraPixelGrey(int tipo)
{

    int prob, valor;

    prob = rand() % 100;

    if (tipo < 0)
    {
        if (prob < 80)
            valor = rand() % 128;

        else
            valor = rand() % 256;
    }
    else if (tipo > 0)
    {
        if (prob < 80)
            valor = rand() % 128 + 128;

        else
            valor = rand() % 256;
    }
    else
        valor = rand() % 256;

    return (unsigned char)valor;
}
// Q9
int geraImgGray(imgGray img, int tipo)
{
    if (img.img == NULL || img._img == NULL)
        return 0;

    for (int i = 0; i < img.nCol * img.nLin; i++)
    {
        img._img[i] = geraPixelGrey(tipo);
    }
    return 1;
}
// Q10
int geraImgRGB(imgRGB img, int tipo)
{
    if (img.img == NULL || img._img == NULL)
        return 0;

    for (int i = 0; i < img.nCol * img.nLin; i++)
    {
        img._img[i].R = geraPixelGrey(tipo);
        img._img[i].G = geraPixelGrey(tipo);
        img._img[i].B = geraPixelGrey(tipo);
    }

    return 1;
}

// Q11
int pixelGrayMax(imgGray img)
{
    int max = 0;

    for (int i = 0; i < img.nLin * img.nCol; i++)
    {
        if (max < img._img[i])
        {
            max = img._img[i];
        }
    }

    return max;
}

int pixelGrayMin(imgGray img)
{
    int min = 255;

    for (int i = 0; i < img.nLin * img.nCol; i++)
    {
        if (min > img._img[i])
        {
            min = img._img[i];
        }
    }

    return min;
}

// Q12
tRGB pixelRGBMax(imgRGB img)
{
    tRGB max = {0, 0, 0};

    for (int i = 0; i < img.nLin * img.nCol; i++)
    {
        if (max.R < img._img[i].R)
        {
            max.R = img._img[i].R;
        }
        if (max.G < img._img[i].G)
        {
            max.G = img._img[i].G;
        }
        if (max.B < img._img[i].B)
        {
            max.B = img._img[i].B;
        }
    }

    return max;
}

tRGB pixelRGBMin(imgRGB img)
{
    tRGB min = {255, 255, 255};

    for (int i = 0; i < img.nLin * img.nCol; i++)
    {
        if (min.R > img._img[i].R)
        {
            min.R = img._img[i].R;
        }
        if (min.G > img._img[i].G)
        {
            min.G = img._img[i].G;
        }
        if (min.B > img._img[i].B)
        {
            min.B = img._img[i].B;
        }
    }

    return min;
}

// Q13
//  Função para somar os valores dos pixels por linha em uma imagem em escala de cinza
int *somaPorLinhasGray(imgGray img)
{
    // Aloca memória para armazenar as somas das linhas
    int *somaL = (int *)malloc(img.nLin * sizeof(int));

    // Percorre cada linha da imagem
    for (int i = 0; i < img.nLin; i++)
    {
        somaL[i] = 0; // Inicializa a soma da linha i com 0
        // Percorre cada coluna da linha i
        for (int j = 0; j < img.nCol; j++)
        {
            somaL[i] += img.img[i][j]; // Soma o valor do pixel [i][j] à soma da linha i
        }
    }

    // Retorna o ponteiro para o array contendo as somas das linhas
    return somaL;
}

// Função para somar os valores dos pixels por coluna em uma imagem em escala de cinza
int *somaPorColunasGray(imgGray img)
{
    // Aloca memória para armazenar as somas das colunas
    int *somaC = (int *)malloc(img.nCol * sizeof(int));

    // Percorre cada coluna da imagem
    for (int i = 0; i < img.nCol; i++)
    {
        somaC[i] = 0; // Inicializa a soma da coluna i com 0
        // Percorre cada linha da coluna i
        for (int j = 0; j < img.nLin; j++)
        {
            somaC[i] += img.img[j][i]; // Soma o valor do pixel [j][i] à soma da coluna i
        }
    }

    // Retorna o ponteiro para o array contendo as somas das colunas
    return somaC;
}

// Q14
//  Função para somar os valores dos componentes RGB de cada linha em uma imagem RGB
tRGB *somaPorLinhasRGB(imgRGB img)
{
    // Aloca memória para armazenar as somas de cada linha (cada linha tem um valor RGB)
    tRGB *linhas = (tRGB *)malloc(img.nLin * sizeof(tRGB));

    // Percorre cada linha da imagem
    for (int i = 0; i < img.nLin; i++)
    {
        // Inicializa os valores RGB da soma da linha com 0
        linhas[i].R = 0;
        linhas[i].G = 0;
        linhas[i].B = 0;

        // Percorre cada coluna da linha atual para somar os valores RGB dos pixels
        for (int j = 0; j < img.nCol; j++)
        {
            linhas[i].R += img.img[i][j].R; // Soma o valor do componente Red (R)
            linhas[i].G += img.img[i][j].G; // Soma o valor do componente Green (G)
            linhas[i].B += img.img[i][j].B; // Soma o valor do componente Blue (B)
        }
    }

    // Retorna o ponteiro para o array contendo as somas RGB de cada linha
    return linhas;
}

// Função para somar os valores dos componentes RGB de cada coluna em uma imagem RGB
tRGB *somaPorColunasRGB(imgRGB img)
{
    // Aloca memória para armazenar as somas de cada coluna (cada coluna tem um valor RGB)
    tRGB *colunas = (tRGB *)malloc(img.nCol * sizeof(tRGB));

    // Percorre cada coluna da imagem
    for (int i = 0; i < img.nCol; i++)
    {
        // Inicializa os valores RGB da soma da coluna com 0
        colunas[i].R = 0;
        colunas[i].G = 0;
        colunas[i].B = 0;

        // Percorre cada linha da coluna atual para somar os valores RGB dos pixels
        for (int j = 0; j < img.nLin; j++)
        {
            colunas[i].R += img.img[j][i].R; // Soma o valor do componente Red (R)
            colunas[i].G += img.img[j][i].G; // Soma o valor do componente Green (G)
            colunas[i].B += img.img[j][i].B; // Soma o valor do componente Blue (B)
        }
    }

    // Retorna o ponteiro para o array contendo as somas RGB de cada coluna
    return colunas;
}

// Q15
//  Função que calcula a soma total de todos os pixels em uma imagem em escala de cinza (Gray)
int somaTotalGray(imgGray img)
{
    // Variável para armazenar a soma total dos pixels
    int somaT15 = 0;

    // Percorre todas as linhas da imagem
    for (int i = 0; i < img.nLin; i++)
    {
        // Percorre todas as colunas da linha atual
        for (int j = 0; j < img.nCol; j++)
        {
            // Soma o valor do pixel atual (img.img[i][j]) à soma total
            somaT15 += img.img[i][j];
        }
    }

    // Retorna a soma total de todos os pixels da imagem
    return somaT15;
}

// Q16
tRGB somaTotalRGB(imgRGB img)
{
    tRGB somaT16 = {0, 0, 0}; // inicializar as variáveis R, G, B do struct com 0

    /*Soma os valores da imagem bidimensional RGB imagem2 (chamada de img no parâmetro)
    snos canais R, G e B percorrendo nLin e nCol*/
    for (int i = 0; i < img.nLin; i++)
    {
        for (int j = 0; j < img.nCol; j++)
        {
            somaT16.R += img.img[i][j].R;
            somaT16.G += img.img[i][j].G;
            somaT16.B += img.img[i][j].B;
        }
    }
    return somaT16; // retorna a soma acumulada dos canais
}

// Q17
//  Função que conta quantos pixels têm a intensidade igual à especificada
int quantosPixelsGrayNaInt(imgGray img, uchar inten)
{
    int pixelsG = 0;

    // Percorre a imagem bidimensionalmente
    for (int i = 0; i < img.nLin; i++)
    {
        for (int j = 0; j < img.nCol; j++)
        {
            if (img.img[i][j] == inten)
                pixelsG++;
        }
    }

    return pixelsG;
}

// Q18
//  Função que conta quantos pixels têm a intensidade RGB igual à especificada
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten)
{
    int pixelsRGB = 0;

    // Percorre a imagem unidimensionalmente
    for (int i = 0; i < img.nLin; i++)
    {
        for (int j = 0; j < img.nCol; j++)
        {
            if (img.img[i][j].R == inten.R && img.img[i][j].G == inten.G && img.img[i][j].B == inten.B)
                pixelsRGB++;
        }
    }
    return pixelsRGB;
}
