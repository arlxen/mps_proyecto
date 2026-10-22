#include"OPMATRIX.h"

Matrix sumar(Matrix A, Matrix B){
    Matrix R;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
    return R;
}