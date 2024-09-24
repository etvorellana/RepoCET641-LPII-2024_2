#include <stdio.h>
#include <stdlib.h>
#define NSIZE 1024

void alocaVet(int m, double** vet){
    *vet = (double*)malloc(m*sizeof(double));    
}

double* alocaMatriz(int m, int n)
{
    double* mat;
    mat = (double*)malloc(m*n*sizeof(double));
    return mat;
}


void iniciliazaMatriz(double* mat, int m, int n, int tipo)
{
    int tam = m*n;
    for(int i = 0; i < tam; i++){
        if (tipo == 0)
            mat[i] = 1.0;
        else if (tipo == 1)
            mat[i] = (double)rand()/RAND_MAX;
        else
            mat[i] = 0.0;
    }
}

void dgemm(double alpha, double* A, double* B, double beta, double* C, int m, int l, int n)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            C[i*n + j] *= beta;
            for(int k = 0; k < l; k++){
                C[i*n + j] += alpha * A[i*l + k] * B[k * n + j];
            }
        }
    }
}

int testaMult(double* mat, int m, int l, int n)
{
    int tam = n*m;
    for(int i = 0; i < tam; i++){
        if (mat[i] != l)
            return 0;
    }
    return 1;
}

int main(void)
{
    double* matA = alocaMatriz(NSIZE, NSIZE); 
    double* matB = alocaMatriz(NSIZE, NSIZE);
    double* matC = alocaMatriz(NSIZE, NSIZE);
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

    free(matA);
    free(matB);
    free(matC);
    
    return 0;
}