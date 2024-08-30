#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função principal para testar preencheImgCinza, geraPixelCinza e preencheImgPreto
int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    unsigned char img[640][480];

    // Preenche a imagem com valores aleatórios usando rand()
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = rand() % 256; // Gera valores entre 0 e 255
        }
    }

    // 9 e 10: Obtém o valor máximo e mínimo dos pixels
    int max = pixelMax(img);
    int min = pixelMin(img);

    // Exibe os resultados
    printf("\nMaior intensidade de pixel: %d\n", max);
    printf("Menor intensidade de pixel: %d\n\n", min);

    // Testa a função preencheImgCinza
    unsigned char pixel = geraPixelCinza(0); // Gera um valor de pixel com probabilidade uniforme
    preencheImgCinza(img, pixel);
    printf("Pixel [0][0] apos preencheImgCinza: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgCinza: %u\n", img[639][479]);

    // Testa a função preencheImgPreto
    preencheImgPreto(img);
    printf("Pixel [0][0] apos preencheImgPreto: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgPreto: %u\n", img[639][479]);

    // Testa a função preencheImgBranco
    preencheImgBranco(img);
    printf("Pixel [0][0] apos preencheImgBranco: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgBranco: %u\n", img[639][479]);

    // 7: Testa a função drwCirc
    unsigned char ibagem[altura][largura] = {0};
    short int cor = 0;

    printf("\n\nInsira sua cor desejada:\n1 - Vermelho;\n2 - Verde;\n3 - Amarelo;\n4 - Azul;\n5 - Magenta;\n6 - Ciano;\n7 - Branco.\n\n");
    scanf("%hu", &cor);

    drwCirc(ibagem, 300, 200, 50, cor);
    // printf("\x1b[47m");
    return 0;
}