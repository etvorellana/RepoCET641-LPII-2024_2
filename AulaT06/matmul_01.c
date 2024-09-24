#include <stdio.h>
#include <stdlib.h>
#define NSIZE 1024

void iniciliazaMatriz(double mat[NSIZE][NSIZE], int tipo)
{
    for(int i = 0; i < NSIZE; i++){
        for(int j = 0; j < NSIZE; j++){
            if (tipo == 0)
                mat[i][j] = 1.0;
            else if (tipo == 1)
                mat[i][j] = (double)rand()/RAND_MAX;
            else
                mat[i][j] = 0.0;
        }
    }
}

void dgemm(double alpha, double A[NSIZE][NSIZE], double B[NSIZE][NSIZE], double beta, double C[NSIZE][NSIZE])
{
    for(int i = 0; i < NSIZE; i++){
        for(int j = 0; j < NSIZE; j++){
            C[i][j] *= beta;
            for(int k = 0; k < NSIZE; k++){
                C[i][j] += alpha * A[i][k] * B[k][j];
            }
        }
    }
}

int testaMult(double mat[NSIZE][NSIZE])
{
    for(int i = 0; i < NSIZE; i++){
        for(int j = 0; j < NSIZE; j++){
            if (mat[i][j] != NSIZE)
                return 0;
        }
    }
    return 1;
}

int main(void)
{
    double matA[NSIZE][NSIZE]; 
    double matB[NSIZE][NSIZE];
    double matC[NSIZE][NSIZE];
    iniciliazaMatriz(matA, 0);
    iniciliazaMatriz(matB, 0);
    iniciliazaMatriz(matC, 3);

    double alpha = 1, beta = 1;

    dgemm(alpha, matA, matB, beta, matC);
    if (testaMult(matC))
        printf("Multiplicação realizada com sucesso!\n");
    else
        printf("Erro na multiplicação!\n");
    /*
    for(int i = 0; i < NSIZE; i++){
        for(int j = 0; j < NSIZE; j++){
            printf("%.2f ", matC[i][j]);
        }
        printf("\n");
    }
    */


    return 0;
}