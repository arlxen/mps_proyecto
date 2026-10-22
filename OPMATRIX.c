#include"OPMATRIX.h"

//Pre: recibe dos matrices A y B de tamaño N x N 
//Post: devuelve la matriz C que es el resultado de multiplicar A y B
void multiplicar(Matrix A, Matrix B, Matrix R) {
    if (A == NULL || B == NULL || R == NULL) {
        gestionarErrorMatrix(MATRIX_ERROR_NULL);
        return;
    }
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
    if (A == NULL || B == NULL || R == NULL) {
        gestionarErrorMatrix(MATRIX_ERROR_NULL);
        return;
    }
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Pre: recibe dos matrices A y B de tamaño N x N
//Post: devuelve la matriz C que es el resultado de restar A y B
void resta(Matrix A, Matrix B, Matrix R){
    if (A == NULL || B == NULL || R == NULL) {
        gestionarErrorMatrix(MATRIX_ERROR_NULL);
        return;
    }
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

//Pre: recibe una matriz A de tamaño N x N y un escalar k
//Post: devuelve la matriz R que es el resultado de multiplicar A por k
void productoEscalar(Matrix A, int k, Matrix R) {
    if (A == NULL || R == NULL) {
        gestionarErrorMatrix(MATRIX_ERROR_NULL);
        return;
    }
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            R[i][j] = k * A[i][j];
        }
    }
}

void gestionarErrorMatrix(MatrixError error) {
    switch (error) {
        case MATRIX_OK:
            break;
        case MATRIX_ERROR_NULL:
            printf("\n[ERROR OPMATRIX] Se ha recibido una matriz o puntero nulo (NULL).\n");
            break;
        case MATRIX_ERROR_INVALID_OPERATION:
            printf("\n[ERROR OPMATRIX] La operacion solicitada no es valida.\n");
            break;
        case MATRIX_ERROR_FILE_OPEN:
            printf("\n[ERROR OPMATRIX] No se pudo abrir el archivo de matriz.\n");
            break;
        case MATRIX_ERROR_FILE_READ:
            printf("\n[ERROR OPMATRIX] Error al leer los datos de la matriz.\n");
            break;
        case MATRIX_ERROR_FILE_WRITE:
            printf("\n[ERROR OPMATRIX] Error al escribir la matriz en el archivo.\n");
            break;
        default:
            printf("\n[ERROR OPMATRIX] Se ha producido un error desconocido (Codigo: %d).\n", error);
            break;
    }
void simetrica(Matrix A){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = i + 1; j < MATRIX_SIZE; j++){
            if(A[i][j] != A[j][i]){
                printf("La Matriz no es simetrica. \n");
                return;
            }
        }
    }
    printf("La Matriz es simetrica. \n");
}