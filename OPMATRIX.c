#include"OPMATRIX.h"

//Pre: recibe dos matrices A y B de tamaño N x N 
//Post: devuelve la matriz C que es el resultado de multiplicar A y B
void multiplicar(Matrix A, Matrix B, Matrix R) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            R[i][j] = 0; // Inicializamos a cero antes de acumular
            for (int k = 0; k < 5; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

//Pre: recibe dos matrices A y B de tamaño N x N
//Post: devuelve la matriz C que es el resultado de sumar A y B
void sumar(Matrix A, Matrix B, Matrix R){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Pre: recibe dos matrices A y B de tamaño N x N
//Post: devuelve la matriz C que es el resultado de restar A y B
void resta(Matrix A, Matrix B, Matrix R){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

//Pre: recibe una matriz A de tamaño N x N y un escalar k
//Post: devuelve la matriz R que es el resultado de multiplicar A por k
void productoEscalar(Matrix A, int k, Matrix R) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            R[i][j] = k * A[i][j];
        }
    }
}