#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "procimg.h"

#define altura 10
#define largura 10

int main (void){
    srand((unsigned int)time(NULL));
    unsigned char img[altura][largura] = {0};
    int check;

//Q1
    printf("--- Q1: geraLinhaR() --- \n");
    geraLinhaR(img[1], 0);
    unsigned char Q1Valor = img[1][0];
    int Q1Qtde = 0;

    for(int i = 1; i < largura; i++){
        if(img[1][i] == Q1Valor){
            Q1Qtde++;
        }     
    }

    if(Q1Qtde < (largura/3))
        printf("Valores da linha estao randomizados (menos de 30%% de repeticao do primeiro valor)\n");
    else
        printf("Valores da linha possivelmente nao estao randomizados (mais de 30%% de repeticao do primeiro valor)\n");


//Q2
    printf("\n--- Q2: geraImgGreyFull_R ---\n");
    unsigned char Q2Pixel = 100;
    geraImgGreyFull_R(img, Q2Pixel);

    check = 1;
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            if(img[y][x] != Q2Pixel){
                check = 0;
                break;
            }
        }
    }

    if(check)
        printf("Imagem pintada (todos os valores sao iguais)\n");
    else
        printf("Imagem nao pintada corretamente (existem valores diferentes)\n");


//Q3
    printf("\n--- Q3: geraImgGreyB_R ---\n");
    geraImgGreyB_R(img); 
    check = 1;
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            if(img[y][x] != 0){
                check = 0;
                break;
            }
        }
    }

    if(check)
        printf("Imagem pintada de preto (todos os valores sao 0)\n");
    else
        printf("Imagem nao pintada corretamente (existem valores diferentes)\n");


//Q4
    printf("\n--- Q4: geraImgGreyW_R ---\n");
    geraImgGreyW_R(img); 
    check = 1;
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            if(img[y][x] != 255){
                check = 0;
                break;
            }
        }
    }

    if(check)
        printf("Imagem pintada de branco (todos os valores sao 255)\n");
    else
        printf("Imagem nao pintada corretamente (existem valores diferentes)\n");


//Q5
    printf("\n--- Q5: geraImgGrey_R() --- \n");
    geraImgGrey_R(img, 0);    

    unsigned char Q5Valor = img[0][0];
    int Q5Qtde = 0;

    for(int y = 0; y < altura/2; y++){
        for(int x = 1; x < largura/2; x++){
            if(img[y][x] == Q5Valor){
                Q5Qtde++;
            }     
        }
    }

    if(Q5Qtde < ((largura*altura)/3))
        printf("Valores da imagem estao randomizados (menos de 30%% de repeticao do primeiro valor)\n");
    else
        printf("Valores da imagem possivelmente nao estao randomizados (mais de 30%% de repeticao do primeiro valor)\n");


//Q6
    printf("\n--- Q6: pixelMax_R() --- \n");
    geraImgGrey_R(img, 0);    

    unsigned char Q6MaiorPixel = (unsigned char)pixelMax_R(img);
    printf("Retorno da funcao: %u\n", Q6MaiorPixel);

    check = 1;
    for(int y = 0; y < altura/2; y++){
        for(int x = 0; x < largura/2; x++){
            if(img[y][x] > Q6MaiorPixel){
                check = 0;
                break;
            }
        }
    }

    if(check)
        printf("Resultado correto (Nenhum valor maior foi encontrado na amostra)\n");
    else
        printf("Resultado incorreto (outro valor maior foi encontrado)\n");


//Q7
    printf("\n--- Q7: pixelMin_R() --- \n");
    geraImgGrey_R(img, 0);    

    unsigned char Q7MenorPixel = (unsigned char)pixelMin_R(img);
    printf("Retorno da funcao: %u\n", Q7MenorPixel);

    check = 1;
    for(int y = 0; y < altura/2; y++){
        for(int x = 0; x < largura/2; x++){
            if(img[y][x] < Q7MenorPixel){
                check = 0;
                break;
            }     
        }
    }

    if(check)
        printf("Resultado correto (Nenhum valor menor foi encontrado na amostra)\n");
    else
        printf("Resultado incorreto (outro valor menor foi encontrado)\n");


//Q8
    printf("\n--- Q8: somaPorLinhas_R() --- \n");
    for(int x = 0; x < largura; x++){
        img[0][x] = 1;
    }
    
    int Q8Soma[altura] = {0};
    somaPorLinhas_R(img, Q8Soma);

    if(Q8Soma[0] == largura)
       printf("Soma correta (na primeira linha o resultado = largura, pois todos sao = 1\n");
    else
        printf("Soma incorreta (na primeira linha, o resultado deveria ser largura, em que todos sao = 1\n");


//Q9
    printf("\n--- Q9: somaPorColunas_R() --- \n");
    for(int y = 0; y < altura; y++){
        img[y][0] = 1;
    }
    
    int Q9Soma[largura] = {0};
    somaPorColunas_R(img, Q9Soma);

    if(Q9Soma[0] == altura)
       printf("Soma correta (na primeira coluna, o resultado = altura, pois todos sao = 1\n");
    else
        printf("Soma incorreta (na primeira coluna, o resultado deveria ser altura, em que todos sao = 1\n");


//Q10
    printf("\n--- Q10: somaPorTotal_R() --- \n");
    geraImgGreyFull_R(img, 1);

    int Q10Total = altura * largura;

    if(somaPorTotal_R(img) == Q10Total)
       printf("Soma correta (resultado = altura*largura, pois todos sao = 1\n");
    else
        printf("Soma incorreta (resultado deveria ser altura*largura, pois todos sao = 1\n");


//Q11
    printf("\n--- Q11: quantosPixelsNaInt_R() --- \n");
    geraImgGreyB_R(img);    

    for(int x = 0; x < largura; x++){
        img[0][x] = 100;
    }

    if(quantosPixelsNaInt_R(img, 100) == largura)
        printf("Resultado correto (somente a primeira linha contem o pixel, e eh composta por somente esse pixel)\n");
    else
        printf("Resultado incorreto (valor supostamente foi encontrado em outro lugar)\n");


//Q12
    printf("\n--- Q12: quantosPixelsAbaixoDeInt_R() --- \n");
    geraImgGreyFull_R(img, 100);    

    for(int x = 0; x < largura; x++){
        img[0][x] = 99;
    }

    if(quantosPixelsAbaixoDeInt_R(img, 100) == largura)
        printf("Resultado correto (somente a primeira linha contem valores abaixo de int)\n");
    else
        printf("Resultado incorreto (valores menores supostamente foram encontrados em outro lugar)\n");


//Q13
    printf("\n--- Q13: quantosPixelsAcimaDeInt_R() --- \n");
    geraImgGreyFull_R(img, 100);    

    for(int x = 0; x < largura; x++){
        img[0][x] = 101;
    }

    if(quantosPixelsAcimaDeInt_R(img, 100) == largura)
        printf("Resultado correto (somente a primeira linha contem valores acima de int)\n");
    else
        printf("Resultado incorreto (valores maiores supostamente foram encontrados em outro lugar)\n");


    return 0;
}