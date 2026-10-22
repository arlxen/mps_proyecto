#ifndef OPMATRIX_H
#define OPMATRIX_H

#define MATRIX_SIZE 5

typedef int Matrix[MATRIX_SIZE][MATRIX_SIZE];

void multiplicar(Matrix A, Matrix B, Matrix R);
Matrix sumar(Matrix A, Matrix B);

#endif