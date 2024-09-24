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

double** indexaMatriz(double* mat, int m, int n)
{
    double** index;
    index = (double**)malloc(m*sizeof(double*));
    for(int i = 0; i < m; i++){
        index[i] = &mat[i*n];
    }
    return index;
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
    double* A = alocaMatriz(NSIZE, NSIZE); 
    double* B = alocaMatriz(NSIZE, NSIZE);
    double* C = alocaMatriz(NSIZE, NSIZE);

    double** matA = indexaMatriz(A, NSIZE, NSIZE);
    double** matB = indexaMatriz(B, NSIZE, NSIZE);
    double** matC = indexaMatriz(C, NSIZE, NSIZE);
    
    iniciliazaMatriz(A, NSIZE, NSIZE, 0);
    iniciliazaMatriz(B, NSIZE, NSIZE, 0);
    iniciliazaMatriz(C, NSIZE, NSIZE, 3);

    double alpha = 1, beta = 1;

    dgemm(alpha, matA, matB, beta, matC, NSIZE, NSIZE, NSIZE);
    if (testaMult(C, NSIZE, NSIZE, NSIZE))
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
    free(A);
    free(B);
    free(C);
    
    return 0;
}