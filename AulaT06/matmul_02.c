#include <stdio.h>
#include <stdlib.h>
#define NSIZE 2048

void alocaVet(int m, double** vet){
    *vet = (double*)malloc(m*sizeof(double));    
}

double** alocaMatriz(int m, int n)
{
    double** mat;
    mat = (double**)malloc(m*sizeof(double*));
    for(int i = 0; i < m; i++)
    {
        mat[i] = (double*)malloc(n*sizeof(double));
    }
    return mat;
}

void desalocaMatriz(double** mat, int m)
{
    for(int i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void iniciliazaMatriz(double** mat, int m, int n, int tipo)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (tipo == 0)
                mat[i][j] = 1.0;
            else if (tipo == 1)
                mat[i][j] = (double)rand()/RAND_MAX;
            else
                mat[i][j] = 0.0;
        }
    }
}

void dgemm(double alpha, double** A, double** B, double beta, double** C, int m, int l, int n)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            C[i][j] *= beta;
            for(int k = 0; k < l; k++){
                C[i][j] += alpha * A[i][k] * B[k][j];
            }
        }
    }
}

int testaMult(double** mat, int m, int l, int n)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (mat[i][j] != l)
                return 0;
        }
    }
    return 1;
}

int main(void)
{
    double** matA = alocaMatriz(NSIZE, NSIZE); 
    double** matB = alocaMatriz(NSIZE, NSIZE);
    double** matC = alocaMatriz(NSIZE, NSIZE);
    iniciliazaMatriz(matA, NSIZE, NSIZE, 0);
    iniciliazaMatriz(matB, NSIZE, NSIZE, 0);
    iniciliazaMatriz(matC, NSIZE, NSIZE, 3);

    double alpha = 1, beta = 1;

    dgemm(alpha, matA, matB, beta, matC, NSIZE, NSIZE, NSIZE);
    if (testaMult(matC, NSIZE, NSIZE, NSIZE))
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

    desalocaMatriz(matA, NSIZE);
    desalocaMatriz(matB, NSIZE);
    desalocaMatriz(matC, NSIZE);
    
    return 0;
}