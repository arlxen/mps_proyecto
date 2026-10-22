#include"OPMATRIX.h"

//Pre: recibe dos matrices A y B de tamaño N x N 
//Post: devuelve la matriz C que es el resultado de multiplicar A y B
void multiplicar(Matrix A, Matrix B, Matrix R) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            R[i][j] = 0; // Inicializamos a cero antes de acumular
            for (int k = 0; k < 5; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
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