#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "procimg.h"

int main (void){
    /*1
    srand(time(0)); 
    int tipo;
    unsigned char pixel;
    printf("Q1 - Entre com o tipo para gerar o pixel:\n");
    scanf("%d", &tipo);
    pixel = geraGreyPixel(tipo);
    printf("%u", pixel);
    */

    /*2
    unsigned char pixel, img[640][480];
    int i, j;
    printf("Entre com o valor para preencher a imagem:\n");
    scanf("%u", &pixel);
    geraImgGreyFull(img, pixel);
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
    //*/

    /*3
    int i, j;
    unsigned char img[640][480];
    geraImgGreyB(img);
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
    //*/

    /*4
    int i, j;
    unsigned char img[640][480];
    geraImgGreyW(img);
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
    //*/

    /*9
    unsigned char img[640][480];
    imgRandom(img);
    printf("Maior intensidade de pixel: ", pixelMax(img));
    //*/
    
    /*10
    unsigned char img[640][480];
    imgRandom(img);
    printf("Menor intensidade de pixel: ", pixelMin(img));
    //*/
    
    /*12
    unsigned char img[640][480];
    unsigned char hist[256];
    imgHistogram(img, hist);
    */

    return 0;
}