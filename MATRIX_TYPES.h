
#ifndef MATRIX_TYPES_H
#define MATRIX_TYPES_H
#include <stddef.h>
#define MATRIX_SIZE 5
typedef double MatrixElement;
typedef MatrixElement Matrix[MATRIX_SIZE][MATRIX_SIZE];

/* Tipos de operaciones disponibles */

//No se ha usado
typedef enum
{
    OP_SUMAR = 1,
    OP_RESTAR,
    OP_PRODUCTO_ESCALAR,
    OP_MULTIPLICAR,
    OP_SALIR
} MatrixOperation;


/* Códigos de error */
typedef enum
{
    MATRIX_OK = 0,
    MATRIX_ERROR_NULL,
    MATRIX_ERROR_FILE_OPEN,
    MATRIX_ERROR_FILE_READ,
    MATRIX_ERROR_FILE_WRITE,
    MATRIX_ERROR_INVALID_OPERATION
} MatrixError;

#endif
