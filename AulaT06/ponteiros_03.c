#include <stdio.h>
#include <stdlib.h>

int mian(void)
{
    int histo[256] = {0};
    int* listaALunos;
    int qtAlunos;
    printf("Quantos alunos finalizaram a amtrícula? ");
    scanf("%d", &qtAlunos);
    listaALunos = (int*)malloc(qtAlunos*sizeof(int));
    //int listaAlunos[qtAlunos];
    float* media;
    //media = (float*)malloc(qtAlunos* sizeof(float));
    media = (float*)calloc(qtAlunos, sizeof(float));

    float** notas;
    notas = (float**)malloc(qtAlunos*sizeof(float*));
    for(int i = 0; i < qtAlunos; i++)
    {
        notas[i] = (float*)malloc(6*sizeof(float));
    }

    for(int i = 0; i < qtAlunos; i++)
    {
        printf("Alunos %d: ", i+1);
        for(int j = 0; j < 6; j++)
        {
            printf("Nota %d: ", j+1);
            notas[i][j] = rand() % 11;
            printf("%.2f\n", notas[i][j]);
        }
    }

    free(listaALunos);
    free(media);
    for(int i = 0; i < qtAlunos; i++)
    {
        free(notas[i]);
    }
    free(notas);

    return 0;
}