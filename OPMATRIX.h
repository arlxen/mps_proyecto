#ifndef OPMATRIX_H
#define OPMATRIX_H
#include"MATRIX_TYPES.h"

void multiplicar(Matrix A, Matrix B, Matrix R);
void sumar(Matrix A, Matrix B, Matrix R);
void resta(Matrix A, Matrix B, Matrix R);
void productoEscalar(Matrix A, int k, Matrix R);
<<<<<<< HEAD
void simetrica(Matrix A);
=======

// Funcion centralizada para controlar y notificar los errores producidos
void gestionarErrorMatrix(MatrixError error);

>>>>>>> d1d5ae989bfff7ed1ded41f5a1df2d0920ed712e
#endif