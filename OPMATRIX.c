#include"OPMATRIX.h"

//Pre: recibe dos matrices A y B de tamaño N x N 
//Post: devuelve la matriz C que es el resultado de multiplicar A y B
void multiplicarMatrices(int A[MATRIX_SIZE][MATRIX_SIZE], int B[MATRIX_SIZE][MATRIX_SIZE], int C[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0; // Inicializar elemento acumulador
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
Matrix sumar(Matrix A, Matrix B){
    Matrix R;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
    return R;
}