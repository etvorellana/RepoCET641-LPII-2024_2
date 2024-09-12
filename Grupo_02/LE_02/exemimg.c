#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Declaração das variáveis
    unsigned char linha[LARGURA];
    unsigned char img[ALTURA][LARGURA];

    // QUESTAO 1: Teste da função geraLinha com tipo = 0 (aleatório)
    geraLinha(linha, 0);
    printf("\nPrimeiros 10 valores de linha: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", linha[i]);
    }
    printf("\n");

    // QUESTAO 2: Teste da função geraImgGreyFull_R, preenchendo todos os pixeis com o valor predeterminado 100
    geraImgGreyFull_R(img, 100);
    printf("Primeiros 10 valores de img apos geraImgGreyFull_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 3: Teste da função geraImgGreyB_R, retornando uma imagem preta
    geraImgGreyB_R(img);
    printf("Primeiros 10 valores de img apos geraImgGreyB_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 4: Teste da função geraImgGreyW_R, retornando uma imagem branca
    geraImgGreyW_R(img);
    printf("Primeiros 10 valores de img apos geraImgGreyW_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 5: Teste da função geraImgGrey, o parametro altera a probablilidade do tom do pixel.
    geraImgGrey(img, 1);
    printf("Primeiros 10 valores de img apos geraImgGrey: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 6: Teste da função pixelMax_R, retorna o pixel de maior intensidade
    // Preenche a matriz com um valor constante e coloca um valor maior em uma posição específica
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            img[i][j] = 100;
        }
    }

    img[ALTURA - 1][LARGURA - 1] = 200;
    int pixel_max = pixelMax_R(img);

    printf("\nPixel de maior intensidade: %d\n", pixel_max);

    // QUESTAO 7: Teste da função pixelMin_R, retorna o pixel de menor intensidade
    // Preenche a matriz com um valor constante (reutiliza o for da Q06) e coloca um valor menor em uma posição específica
    img[ALTURA - 1][LARGURA - 1] = 50;     
    int pixel_min = pixelMin_R(img);

    printf("Pixel de menor intensidade: %d\n", pixel_min);

    // QUESTAO 08, 09 e 10: Teste das funcoes somaPorLinhas_R, somaPorColunas_R e somaPorTotal_R
    int somaL[ALTURA];
    int somaC[LARGURA];
    int somaTotal;

    // Inicializa a imagem com valores para teste
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            img[i][j] = 1; // Preenche com 1
        }
    }

    somaPorLinhas_R(img, somaL);
    somaPorColunas_R(img, somaC);
    somaTotal = somaPorTotal_R(img);

    // Verificação
    int erroLinha = 0;
    for (int i = 0; i < ALTURA; i++) {
        if (somaL[i] != LARGURA) {
            erroLinha = 1; 
            break;
        }
    }

    if (erroLinha) printf("\nErro nas somas das linhas.\n");
    else printf("\nSoma das linhas correta.\n");

    int erroColuna = 0;
    for (int i = 0; i < LARGURA; i++) {
        if (somaC[i] != ALTURA) {
            erroColuna = 1;
            break;
        }
    }

    if(erroColuna) printf("Erro nas somas das colunas.\n");
    else printf("Soma das colunas correta.\n");

    if (somaTotal != ALTURA * LARGURA) printf("\nErro na soma total.\n");
    else printf("Soma total: %d (Resultado correto)\n", somaTotal);

    // QUESTOES 11, 12 e 13: Preenche a imagem com valores de exemplo (aqui, todos os pixels com valor 128)
    for(int i = 0; i < ALTURA; i++) {
        for(int j = 0; j < LARGURA; j++) {
            img[i][j] = 128;
        }
    }

    unsigned char intensidade = 128; // Intensidade teste
    img[0][0] = intensidade - 1; // Altera p/ um pixel abaixo da intensidade teste
    img[0][1] = intensidade + 1; // Altera p/ um pixel acima da intensidade teste


    // Testa a função para contar pixels com intensidade específica
    int resultado1 = quantosPixelsNaInt_R(img, intensidade);
    printf("\nPixels com intensidade %d: %d", intensidade, resultado1);
    
    if (resultado1 == (ALTURA * LARGURA) - 2) printf(" (Resultado correto)\n");
    else printf(" (Resultado incorreto)\n");

    // Testa a função para contar pixels abaixo de uma intensidade
    int resultado2 = quantosPixelsAbaixoDeInt_R(img, intensidade);
    printf("Pixels com intensidade menor que %d: %d", intensidade, resultado2);

    if (resultado2 == 1) printf(" (Resultado correto)\n");
    else printf(" (Resultado incorreto)\n");

    // Testa a função para contar pixels acima de uma intensidade
    int resultado3 = quantosPixelsAcimaDeInt_R(img, intensidade);
    printf("Pixels com intensidade maior que %d: %d", intensidade, resultado3);

    if (resultado3 == 1) printf(" (Resultado correto)\n");
    else printf(" (Resultado incorreto)\n");


    return 0;
}