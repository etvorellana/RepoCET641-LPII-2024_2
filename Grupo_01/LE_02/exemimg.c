#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "procimg.h"

int main (void){
    srand(time(0));

/*Q1
    unsigned char img[480][640] = {0};
    geraLinhaR(img[5], 0);
    displayImg(img);    
//*/

/*Q2    
    unsigned char img[480][640];
    displayImg(img);    

    printf("\n\n");
    geraImgGreyFull_R(img, 100);
    displayImg(img);    
   
//*/

/*Q3
    unsigned char img[480][640];
    displayImg(img);

    printf("\n\n"); 
    geraImgGreyB_R(img); 
    displayImg(img);      
//*/

/*Q4
    unsigned char img[480][640];
    displayImg(img);

    printf("\n\n"); 
    geraImgGreyW_R(img); 
    displayImg(img);      
//*/

/*Q5
    unsigned char img[480][640];
    displayImg(img);

    printf("\n\n"); 
    geraImgGrey_R(img, 0);    
    displayImg(img);      
//*/

/*Q6
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("\n\n%d", pixelMax_R(img));  
//*/

/*Q7
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("%d", pixelMin_R(img));  
//*/

/*Q8
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    int soma[480] = {0};
    somaPorLinhas_R(img, soma);

    printf("\n\n");
    for(int i = 0; i < 480; i++)
        printf("%d - %d\n", i, soma[i]); 
//*/

/*Q9
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    int soma[640] = {0};
    somaPorColunas_R(img, soma);

    printf("\n\n");
    for(int i = 0; i < 640; i++)
        printf("%d - %d\n", i, soma[i]); 
//*/

/*Q10
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("Soma total: %d", somaPorTotal_R(img));  
//*/

/*Q11
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("\n\n%d \n\n", quantosPixelsNaInt_R(img, 100));

    geraImgGreyFull_R(img, 100);
    displayImg(img);
    printf("\n\n%d", quantosPixelsNaInt_R(img, 100));
  
//*/

/*Q12
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("\n\n%d \n\n", quantosPixelsAbaixoDeInt_R(img, 100));

    geraImgGreyFull_R(img, 50);
    displayImg(img);
    printf("\n\n%d", quantosPixelsAbaixoDeInt_R(img, 100));
//*/

/*Q13
    unsigned char img[480][640];
    geraImgGrey_R(img, 0);
    displayImg(img);

    printf("\n\n%d \n\n", quantosPixelsAcimaDeInt_R(img, 100));

    geraImgGreyFull_R(img, 50);
    displayImg(img);
    printf("\n\n%d", quantosPixelsAcimaDeInt_R(img, 100));
//*/

/*Q14
//*/

    return 0;
}