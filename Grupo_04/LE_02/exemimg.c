#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

/*INSTRUÇÕES:
 * Para compilar via terminal: gcc -o main exemimg.c procimg.c
 * Para executar após compilar: ./main
 */

// Função para o Exercício 1
void exercicio1()
{
    printf("\nQuestão 1\n");
    srand(time(NULL));
    int type;
    unsigned char lin[640] = {0};

    printf("\nQual tipo? 1, 0 ou -1: ");
    scanf("%i", &type);

    geraLinhaR(lin, type);

    int countAcima = 0, countAbaixo = 0;

    for (int i = 0; i < 640; i++)
        if (lin[i] >= 128)
            countAcima++;
        else
            countAbaixo++;

    printf("\n - Acima: %d\n - Abaixo: %d", countAcima, countAbaixo);
}

// Função para o Exercício 2
void exercicio2()
{
    printf("\nQuestão 2\n");
    unsigned char lin[480][640] = {0};
    unsigned char pixel;

    printf("Qual o valor do pixel? (0 - 255)\n");
    scanf("%i", &pixel);

    geraImgGreyFull_R(lin, pixel);

    int count = 0;
    for (int i = 0; i < 480; i++)
        for (int j = 0; j < 640; j++)
            if (lin[i][j] == pixel)
                count++;

    printf("%d foi repetido %d vezes\n", pixel, count);
}

// Função para os Exercícios 3 e 4
void exercicio3e4()
{

    unsigned char lin3[480][640] = {0};
    unsigned char lin4[480][640] = {0};

    geraImgGreyB_R(lin3);
    geraImgGreyW_R(lin4);

    int count = 0;
    int count4 = 0;
    for (int i = 0; i < 480; i++)
    {
        for (int j = 0; j < 640; j++)
        {
            if (lin3[i][j] == 0 || lin3[i][j] == 255)
                count++;
            if (lin4[i][j] == 0 || lin4[i][j] == 255)
                count4++;
        }
    }

    printf("\nQuestão 3:\n %d foi repetido %d vezes", 0, count);
    printf("\nQuestão 4:\n %d foi repetido %d vezes", 255, count4);
}

// Função para o Exercício 5
void exercicio5()
{
    printf("\nQuestão 5\n");
    unsigned char lin[480][640];
    int tipo;

    printf("Qual tipo? 1, 0 ou -1\n");
    scanf("%i", &tipo);

    geraImgGrey_R(lin, tipo);

    int countAbaixo = 0;
    int countAcima = 0;
    for (int i = 0; i < 480; i++)
        for (int j = 0; j < 640; j++)
            if (lin[i][j] > 128)
                countAcima++;
            else
                countAbaixo++;

    printf("Tivemos %d acima de 128 e %d abaixo\n", countAcima, countAbaixo);
}

// Função para o Exercício 6
void exercicio6()
{
    printf("\nQuestão 6");
    unsigned char img[HEIGTH][WIDTH] = {0};
    img[0][1] = 125;

    int maiorIntensidade = pixelMax_R(img);

    printf("\n - O pixel com maior intensidade é %d", maiorIntensidade);
}

// Função para o Exercício 7
void exercicio7()
{
    printf("\nQuestão 7\n");
    unsigned char img[HEIGTH][WIDTH] = {255};
    img[0][1] = 2;

    int menorInten = pixelMin_R(img);

    printf(" - O pixel com menor intensidade é %d", menorInten);
}

// Função para o Exercício 8 e 9
void exercicio8e9()
{
    printf("\nQuestão 8 e 9\n");
    unsigned char lin[HEIGTH][WIDTH] = {1};
    int somaLin[HEIGTH] = {0};
    int somaCol[WIDTH] = {0};

    somaPorLinhas_R(lin, somaLin);
    somaPorColunas_R(lin, somaCol);

    for (int i = 0; i < HEIGTH; i++)
    {
        printf("Linha %d = %d\n", i + 1, somaLin[i]);
    }

    for (int i = 0; i < WIDTH; i++)
    {
        printf("Coluna %d = %d\n", i + 1, somaCol[i]);
    }
}

// Função para o Exercício 10
void exercicio10()
{
    printf("\nQuestão 10\n");
    unsigned char img[HEIGTH][WIDTH] = {1};

    int somaTotal = somaPorTotal_R(img);

    printf("A soma total dos pixels da imagem é: %d\n", somaTotal);
}

// Função para o Exercício 11
void exercicio11()
{
    printf("\nQuestão 11\n");
    unsigned char img[HEIGTH][WIDTH] = {0};
    img[0][1] = 225;

    int qtd = quantosPixelsNaInt_R(img, 225);

    printf("A intensidade %d ocorre %d vezes\n", 225, qtd);
}

// Função para o Exercício 12
void exercicio12()
{
    printf("\nQuestão 12\n");
    unsigned char img[HEIGTH][WIDTH] = {244};
    img[0][1] = 225;

    int qtd = quantosPixelsAbaixoDeInt_R(img, 225);

    printf("Os valores abaixo da intensidade %d ocorrem %d vezes\n", 225, qtd);
}

// Função para o Exercício 13
void exercicio13()
{
    printf("\nQuestão 13\n");
    unsigned char img[HEIGTH][WIDTH] = {0};
    img[0][1] = 55;

    int qtd = quantosPixelsAcimaDeInt_R(img, 56);

    printf("\nOs valores acima da intensidade %d ocorrem %d vezes\n", 56, qtd);
}

int main(void)
{
    exercicio1();
    exercicio2();
    exercicio3e4();
    exercicio5();
    exercicio6();
    exercicio7();
    exercicio8e9();
    exercicio10();
    exercicio11();
    exercicio12();
    exercicio13();
    return 0;
}
