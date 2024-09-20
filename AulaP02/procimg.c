#include <stdlib.h>
#include <math.h>
#include "procimg.h"



/* Ajuste lambda para controlar o enviesamento */
unsigned char nonUniformRandom(double lambda)
{
    // Gera um número aleatório entre 0 e 1
    double u = rand() / (RAND_MAX + 1.0);
    
    // Aplica a transformação exponencial
    double x = -log(1 - u) / lambda;
    
    // Escala para o intervalo [0, 255]
    x *= 255;
    // Garante que o valor esteja no intervalo [0, 255]
    x = (x > 255)?255:x;

    unsigned char pixel = (unsigned char)x;
    
    return pixel;
}

unsigned char geraPixel(int tipo)
{
    if (tipo < 0)
    {
        return nonUniformRandom(5.0);
    }
    else if(tipo == 0)
    {
        return (unsigned char) rand() % 256;
    }
    else
    {
        return (unsigned char)255 - nonUniformRandom(5.0);
    }
}   

void geraImagem(unsigned char **img, int largura, int altura, int tipo)
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            img[i][j] = geraPixel(tipo);
        }
    }
}

void geraImgGreyFull(unsigned char img[480][640], unsigned char pixel)
{
    int altura = 480;
    int largura = 640;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            img[i][j] = pixel;
        }
    }
}
