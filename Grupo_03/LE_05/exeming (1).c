#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int nLin = 5, nCol = 5;
    printf("Questao 1\n");

    // Questão 1: Aloca a imagem em tons de cinza
    imgGray imagem = alocaImagemGray(nLin, nCol);
    if (imagem._img == NULL)
    {
        printf("Falha na alocacao da imagem\n");
        return 1;
    }
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            imagem._img[i * imagem.nCol + j] = 128;
        }
    }
    bool erro = false;
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            if (imagem._img[i * imagem.nCol + j] != 128)
            {
                printf("Erro! Imagem gerada errada no pixel [%d][%d].\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro)
    {
        printf("Imagem gerada com sucesso!\n");
    }
    free(imagem._img);
    free(imagem.img);
    printf("\n------------------------------------------------------------\n");

    // Questão 2: Aloca a imagem RGB
    printf("\nQuestao 2\n");
    imgRGB imagem2 = alocaImagemRGB(nLin, nCol);
    if (imagem2.img == NULL)
    {
        printf("Falha na alocacao da imagem RGB\n");
        return 1;
    }
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            imagem2.img[i][j].R = 0;
            imagem2.img[i][j].G = 1;
            imagem2.img[i][j].B = 2;
        }
    }
    erro = false;
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            if (imagem2.img[i][j].R != 0)
            {
                printf("Erro! Componente R preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
            if (imagem2.img[i][j].G != 1)
            {
                printf("Erro! Componente G preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
            if (imagem2.img[i][j].B != 2)
            {
                printf("Erro! Componente B preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro)
    {
        printf("Imagem RGB gerada com sucesso!\n");
    }
    for (i = 0; i < imagem2.nLin; i++)
    {
        free(imagem2.img[i]);
    }
    free(imagem2._img);
    free(imagem2.img);
    printf("\n------------------------------------------------------------\n");

    // Questão 3: Preenchimento com um valor específico
    uchar pixel;
    printf("\nQuestao 3\n");
    printf("Digite o pixel que quer preencher a imagem: ");
    scanf("%hhu", &pixel);
    imgGray imagem3 = alocaImagemGray(nLin, nCol);
    if (imagem3.img == NULL)
    {
        printf("Falha na alocacao da imagem em tons de cinza na Questao 3\n");
        return 1;
    }
    // Verificar se a função geraImgGrayFull está funcionando corretamente
    if (geraImgGrayFull(imagem3, pixel) == 1)
    {
        erro = false;
    }
    else
    {
        erro = true;
        return 1;
    }
    if (!erro)
    {
        for (i = 0; i < nLin; i++)
        {
            for (j = 0; j < nCol; j++)
            {
                if (imagem3.img[i][j] != pixel)
                {
                    printf("Erro! O pixel [%d][%d] nao esta com o valor correto.\n", i, j);
                    erro = true;
                }
            }
        }
    }
    if (!erro)
    {
        printf("\nImagem gerada com sucesso!\n");
    }
    for (i = 0; i < imagem3.nLin; i++)
    {
        free(imagem3.img[i]);
    }
    free(imagem3._img);
    free(imagem3.img);
    printf("\n------------------------------------------------------------\n");

    // Questão 4: Preenchimento de imagem RGB com um valor específico

    printf("\nQuestao 4\n");
    tRGB cores;
    cores.R = 0;
    cores.G = 1;
    cores.B = 2;
    imgRGB imagem4 = alocaImagemRGB(nLin, nCol);

    // Verifica se a memoria foi alocada corretamente
    if (imagem4.img == NULL)
    {
        printf("Falha na alocacao da imagem RGB na Questao 4\n");
        return 1;
    }
    // verificar se a função geraImgRGBFull está funcionando corretamente
    if (geraImgRGBFull(imagem4, cores) == 1)
    {
        erro = false;
    }
    else
    {
        erro = true;
    }
    // Verifica se a imagem foi preenchida corretamente
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            if (imagem4.img[i][j].R != 0)
            {
                printf("Erro! Componente R preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem4.img[i][j].G != 1)
            {
                printf("Erro! Componente G preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem4.img[i][j].B != 2)
            {
                printf("Erro! Componente B preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    printf("\nImagem gerada com sucesso!\n");

    // Libera a memoria alocada
    for (i = 0; i < imagem4.nLin; i++)
    {
        free(imagem4.img[i]);
    }
    free(imagem4._img);
    free(imagem4.img);
    printf("\n------------------------------------------------------------\n");

    // Questão 5: Preenchimento de imagem com 0
    printf("\nQuestao 5");
    imgGray imagem5 = alocaImagemGray(nLin, nCol);
    // Verifica se a imagem foi alocada corretamente
    if (imagem5.img == NULL)
    {
        printf("Falha na alocacao da imagem em tons de cinza na Questao 3\n");
        return 1;
    }
    // Verifica se a função geraImgGrayFull está funcionando corretamente
    if (geraImgGrayB(imagem5) == 1)
    {
        erro = false;
    }
    else
    {
        erro = true;
    }
    // Verifica se a imagem foi preenchida corretamente
    for (i = 0; i < nLin; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            if (imagem5.img[i][j] != 0)
            {
                printf("Erro! O pixel [%d][%d] não está com o valor correto.\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    if (!erro)
    {
        printf("\nImagem gerada com sucesso!\n");
    }
    // Libera a memoria alocada
    for (i = 0; i < imagem5.nLin; i++)
    {
        free(imagem5.img[i]);
    }
    free(imagem5._img);
    free(imagem5.img);
    printf("\n------------------------------------------------------------\n");

    // funcoes 6-10
    imgGray imagemC;
    imgRGB imagemCrgb;
    int teste = 0;
    imagemC = alocaImagemGray(10, 10);
    imagemCrgb = alocaImagemRGB(30, 30);
    if (imagemC._img == NULL || imagemC.img == NULL)
        printf("Falha na alocacao da memoria!\n");
    if (imagemCrgb._img == NULL || imagemCrgb.img == NULL)
        printf("Falha na alocacao da memoria!\n");

    // funcao 6
    geraImgRGBB(imagemCrgb);

    teste = 0;
    for (i = 0; i < imagemCrgb.nCol * imagemCrgb.nLin; i++)
        if (imagemCrgb._img[i].R || imagemCrgb._img[i].G || imagemCrgb._img[i].B)
            teste = 1;

    if (teste)
        printf("\nExecucao da funcao 6 falhou");
    else
        printf("\nExecucao da funcao 6 teve exito");

    printf("\n------------------------------------------------------------\n");
    // funcao 7
    geraImgGrayW(imagemC);

    teste = 0;
    for (i = 0; i < imagemC.nCol * imagemC.nLin; i++)
        if (imagemC._img[i] != 255)
            teste = 1;
    if (teste)
        printf("\nExecucao da funcao 7 falhou");
    else
        printf("\nExecucao da funcao 7 teve exito");
    printf("\n------------------------------------------------------------\n");
    // funcao 8

    geraImgRGBW(imagemCrgb);

    teste = 0;
    for (i = 0; i < imagemCrgb.nCol * imagemCrgb.nLin; i++)
        if (imagemCrgb._img[i].R != 255 || imagemCrgb._img[i].G != 255 || imagemCrgb._img[i].B != 255)
            teste = 1;
    if (teste)
        printf("\nExecucao da funcao 8 falhou");
    else
        printf("\nExecucao da funcao 8 teve exito");
    printf("\n------------------------------------------------------------\n");
    // funcao 9
    geraImgGray(imagemC, 1);
    int maior = 0, menor = 0;
    teste = 0;

    for (i = 0; i < imagemC.nCol * imagemC.nLin; i++)
    {
        if (imagemC._img[i] >= 128)
            maior++;
        else
            menor++;
    }
    if (maior < menor)
        teste = 1;

    if (teste)
        printf("\nExecucao da funcao 9 falhou");
    else
        printf("\nExecucao da funcao 9 teve exito");
    printf("\n------------------------------------------------------------\n");
    // funcao 10
    geraImgRGB(imagemCrgb, 1);
    maior = 0;
    menor = 0;
    teste = 0;

    for (i = 0; i < imagemCrgb.nCol * imagemCrgb.nLin; i++)
    {
        if (imagemCrgb._img[i].R >= 128)
            maior++;
        else
            menor++;
        if (imagemCrgb._img[i].G >= 128)
            maior++;
        else
            menor++;
        if (imagemCrgb._img[i].B >= 128)
            maior++;
        else
            menor++;
    }
    if (maior < menor)
        teste = 1;

    if (teste)
        printf("\nExecucao da funcao 10 falhou");
    else
        printf("\nExecucao da funcao 10 teve exito");

    free(imagemC._img);
    free(imagemC.img);
    free(imagemCrgb._img);
    free(imagemCrgb.img);

    printf("\n------------------------------------------------------------\n");
    printf("\nQUESTAO 11\n");

    imgGray imagem11 = alocaImagemGray(3, 4);

    for (int i = 0; i < 4 * 3; i++)
    {
        imagem11._img[i] = 7;
    }

    imagem11._img[3] = 4;
    imagem11._img[7] = 15;

    for (int i = 0; i < 4 * 3; i++)
    {
        if (i % 4 == 0)
        {
            printf("\n");
        }

        printf("%3d", imagem11._img[i]);
    }

    printf("\n\n--> MAX: %d", pixelGrayMax(imagem11));
    printf("\n\n--> MIN: %d\n", pixelGrayMin(imagem11));

    free(imagem11._img);
    free(imagem11.img);

    printf("\n------------------------------------------------------------\n");
    printf("\nQUESTAO 12\n");

    imgRGB imagem12;
    imagem12.nCol = 4;
    imagem12.nLin = 3;
    imagem12._img = (tRGB *)malloc(imagem12.nCol * imagem12.nLin * sizeof(tRGB));

    for (int i = 0; i < imagem12.nLin * imagem12.nCol; i++)
    {
        imagem12._img[i] = (tRGB){
            7, 7, 7};
    }

    imagem12._img[3] = (tRGB){
        15, 14, 13};
    imagem12._img[7] = (tRGB){
        4, 3, 2};

    for (int i = 0; i < imagem12.nLin * imagem12.nCol; i++)
    {
        if (i % imagem12.nCol == 0)
        {
            printf("\n");
        }
        printf("  {R:%d, G:%d, B:%d}  ", imagem12._img[i].R, imagem12._img[i].G, imagem12._img[i].B);
    }

    printf("\n\n--> MAX RED: %d", pixelRGBMax(imagem12).R);
    printf("\n\n--> MIN RED: %d", pixelRGBMin(imagem12).R);
    printf("\n\n--> MAX GREEN: %d", pixelRGBMax(imagem12).G);
    printf("\n\n--> MIN GREEN: %d", pixelRGBMin(imagem12).G);
    printf("\n\n--> MAX BLUE: %d", pixelRGBMax(imagem12).B);
    printf("\n\n--> MIN BLUE: %d\n", pixelRGBMin(imagem12).B);

    free(imagem12._img);
    free(imagem12.img);
    printf("\n------------------------------------------------------------\n");
    // funcao 13
    printf("\nQUESTAO 13:\n");

    // Aloca uma imagem em escala de cinza com 7 linhas e 4 colunas
    imgGray img13 = alocaImagemGray(7, 4);

    // Declaração de ponteiros para armazenar as somas das linhas e colunas
    int *somaC13;
    int *somaL13;

    // Preenche a imagem com o valor 1 em todos os pixels
    for (i = 0; i < img13.nLin; i++)
    {
        for (j = 0; j < img13.nCol; j++)
        {
            img13.img[i][j] = 1; // Atribui o valor 1 ao pixel [i][j]
        }
    }

    // Calcula a soma dos valores dos pixels por linha e coluna
    somaL13 = somaPorLinhasGray(img13);  // Soma os valores de cada linha
    somaC13 = somaPorColunasGray(img13); // Soma os valores de cada coluna

    printf("\nlinhas: \n");
    for (i = 0; i < img13.nLin; i++)
    {
        // Verifica se a soma da linha é igual ao número de colunas
        if (somaL13[i] != img13.nCol)
        {
            printf("Erro na funcao 13 de linhas!!!! %d\n", somaL13[i]); // Imprime erro se a soma for incorreta
            break;                                                      // Interrompe o laço em caso de erro
        }
        else
        {
            if (i == img13.nLin - 1)
            {
                printf("Funcao 13 de linhas deu certo: %d\n", somaL13[i]); // Imprime a ultima soma correta da linha
            }
        }
    }

    printf("\ncolunas: \n");
    for (i = 0; i < img13.nCol; i++)
    {
        // Verifica se a soma da coluna é igual ao número de linhas
        if (somaC13[i] != img13.nLin)
        {
            printf("Erro na funcao 13 de colunas!!!! %d\n", somaC13[i]); // Imprime erro se a soma for incorreta
            break;                                                       // Interrompe o laço em caso de erro
        }
        else
        {
            if (i == img13.nCol - 1)
            {
                printf("Funcao 13 de colunas deu certo: %d\n", somaC13[i]); // Imprime a ultima soma correta da coluna
            }
        }
    }

    // Libera a memória alocada para as somas de linhas e colunas
    free(somaC13);
    free(somaL13);

    // Libera a memória da imagem
    free(img13._img);
    free(img13.img);

    // Imprime uma linha separadora
    printf("\n------------------------------------------------------------\n");

    // Q14
    printf("QUESTAO 14:\n\n");

    // Aloca uma imagem RGB com 250 linhas e 200 colunas
    imgRGB img14 = alocaImagemRGB(250, 200);

    // Declaração de ponteiros para armazenar as somas das linhas e colunas
    tRGB *somaC14;
    tRGB *somaL14;

    // Preenche a imagem com valores constantes para os componentes RGB (todos os pixels terão R=1, G=1, B=1)
    for (i = 0; i < img14.nLin; i++)
    {
        for (j = 0; j < img14.nCol; j++)
        {
            img14.img[i][j].R = 1; // Atribui 1 ao componente Red (R)
            img14.img[i][j].G = 1; // Atribui 1 ao componente Green (G)
            img14.img[i][j].B = 1; // Atribui 1 ao componente Blue (B)
        }
    }

    // Calcula a soma dos componentes RGB para cada linha e cada coluna
    somaL14 = somaPorLinhasRGB(img14);  // Soma os valores de cada linha
    somaC14 = somaPorColunasRGB(img14); // Soma os valores de cada coluna

    // Imprime e verifica as somas das linhas
    printf("linhas: \n");
    for (i = 0; i < img14.nLin; i++)
    {
        // Verifica se a soma dos componentes R, G, B da linha i é igual ao número de colunas
        if (somaL14[i].R != img14.nCol || somaL14[i].G != img14.nCol || somaL14[i].B != img14.nCol)
        {
            printf("ERRO na funcao 14 de linhas!!!!! %d, %d, %d\n", somaL14[i].R, somaL14[i].G, somaL14[i].B);
            break; // Se houver erro, interrompe o laço
        }
        // Verifica se a última linha foi processada corretamente
        if (i == img14.nCol - 1)
        {
            printf("Deu certo na funcao 14 de linhas!\n"); // Imprime mensagem de sucesso se tudo estiver correto
        }
    }

    // Imprime e verifica as somas das colunas
    printf("\ncolunas: \n");
    for (i = 0; i < img14.nCol; i++)
    {
        // Verifica se a soma dos componentes R, G, B da coluna i é igual ao número de linhas
        if (somaC14[i].R != img14.nLin || somaC14[i].G != img14.nLin || somaC14[i].B != img14.nLin)
        {
            printf("ERRO na funcao 14 de colunas!!!!! %d, %d, %d\n", somaC14[i].R, somaC14[i].G, somaC14[i].B);
            break; // Se houver erro, interrompe o laço
        }
        // Verifica se a última coluna foi processada corretamente
        if (i == img14.nCol - 1)
        {
            printf("Deu certo na funcao 14 de colunas!\n"); // Imprime mensagem de sucesso se tudo estiver correto
        }
    }

    // Libera a memória alocada para a imagem e as somas
    free(img14._img);
    free(img14.img);
    free(somaL14);
    free(somaC14);

    // Imprime uma linha separadora para o fim da questão
    printf("\n------------------------------------------------------------\n");

    // Q15
    printf("QUESTAO 15:\n\n");

    // Declaração de variável para armazenar a soma total dos pixels
    int somaT15;

    // Aloca uma imagem em escala de cinza (Gray) com 100 linhas e 100 colunas
    imgGray img15 = alocaImagemGray(100, 100);

    // Preenche todos os pixels da imagem com o valor 1
    for (int i = 0; i < img15.nLin; i++)
    {
        for (int j = 0; j < img15.nCol; j++)
        {
            img15.img[i][j] = 1; // Atribui o valor 1 a cada pixel
        }
    }

    // Calcula a soma total dos pixels da imagem usando a função somaTotalGray
    somaT15 = somaTotalGray(img15);

    // Verifica se a soma total está correta
    // A soma total deve ser igual ao número de pixels (nLin * nCol), pois todos os pixels têm o valor 1
    if (somaT15 != img15.nLin * img15.nCol)
    {
        // Se a soma for diferente do esperado, imprime uma mensagem de erro
        printf("ERRO na funcao 15!!!! %d", somaT15);
    }
    else
    {
        // Se a soma estiver correta, imprime uma mensagem de sucesso
        printf("Deu certo a funcao 15!! %d", somaT15);
    }

    // Libera a memória alocada para a imagem
    free(img15._img);
    free(img15.img);

    // Imprime uma linha separadora para o fim da questão
    printf("\n------------------------------------------------------------\n");

    // Q16
    printf("QUESTAO 16:\n");
    imgRGB imagem16 = alocaImagemRGB(6, 6);
    if (imagem16.img == NULL || imagem16._img == NULL)
    { // comunicar o usuário a falha na alocação da memória
        printf("Falha na alocacao de memoria da Q16!\n");
    }

    // Preenche a imagem RGB com valores arbitrários
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            imagem16.img[i][j].R = 3; // Define o valor do vermelho (R)
            imagem16.img[i][j].G = 5; // Define o valor do verde (G)
            imagem16.img[i][j].B = 7; // Define o valor do azul (B)
        }
    }

    tRGB totalRGB = somaTotalRGB(imagem16);  // chamada da função
    printf("\nSoma total dos canais RGB\n"); // printa a soma dos canais
    printf("Soma R: %u\n", totalRGB.R);
    printf("Soma G: %u\n", totalRGB.G);
    printf("Soma B: %u\n", totalRGB.B);

    if (totalRGB.R != 3 * 6 * 6 || totalRGB.G != 5 * 6 * 6 || totalRGB.B != 7 * 6 * 6)
        printf("Soma incorreta!\n");
    else
        printf("\nSoma correta!\n");

    free(imagem16._img); // desaloca espaço contínuo
    free(imagem16.img);  // desaloca espaço das linhas

    // Imprime uma linha separadora para o fim da questão
    printf("\n------------------------------------------------------------\n");

    // Q17
    printf("QUESTAO 17:\n");
    imgGray imagem17 = alocaImagemGray(15, 15);

    // verifica se a alocação foi bem-sucedida e comunica o usuário
    if (imagem17.img == NULL || imagem17._img == NULL)
    {
        printf("Falha na alocacao de memoria da Q17!\n");
    }

    // Preenche imagem
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            imagem17.img[i][j] = 12;
        }
    }

    int pixelsG = quantosPixelsGrayNaInt(imagem17, 12);
    printf("\n%d pixels tem intensidade igual a 12.\n", pixelsG);

    // Verifica se o resultado está correto
    if (pixelsG == 15 * 15)
    {
        printf("\nVerificacao bem-sucedida: o numero de pixels esta correto.\n");
    }
    else
    {
        printf("\nErro: numero de pixels incorreto. Esperado: %d, Obtido: %d\n", 15 * 15, pixelsG);
    }
    free(imagem17._img); // desaloca espaço contínuo
    free(imagem17.img);  // desaloca espaço das linhas

    // Imprime uma linha separadora para o fim da questão
    printf("\n------------------------------------------------------------\n");

    // Q18
    printf("QUESTAO 18:\n");
    imgRGB imagem18 = alocaImagemRGB(15, 15);

    // verifica se a alocação foi bem-sucedida e comunica o usuário
    if (imagem18.img == NULL || imagem18._img == NULL)
    {
        printf("Falha na alocacao de memoria da Q18!\n");
    }

    // Preenche a imagem RGB com valores arbitrários
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            imagem18.img[i][j].R = 3; // Define o valor do vermelho (R)
            imagem18.img[i][j].G = 5; // Define o valor do verde (G)
            imagem18.img[i][j].B = 7; // Define o valor do azul (B)
        }
    }
    tRGB intensidade18 = {3, 5, 7}; // define a intensidade que queremos contar
    int pixelsRGB = quantosPixelsRGBNaInt(imagem18, intensidade18);
    printf("\n%d pixels tem intensidade igual a R=3, G=5 e G=7.\n", pixelsRGB);

    // Verifica se o resultado está correto
    if (pixelsRGB == 15 * 15)
    {
        printf("\nVerificacao bem-sucedida: o numero de pixels esta correto.\n");
    }
    else
    {
        printf("\nErro: numero de pixels incorreto. Esperado: %d, Obtido: %d\n", 15 * 15, pixelsRGB);
    }
    free(imagem18._img); // desaloca espaço contínuo
    free(imagem18.img);  // desaloca espaço das linhas
    return 0;
}
