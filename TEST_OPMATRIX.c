
#include <stdio.h>
#include <assert.h>
#include "OPMATRIX.h"

int main(void)
{
    Matrix A, B, R;

    // Prepare test matrices
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            A[i][j] = i + j;
            B[i][j] = 2 * i - j;
        }
    }

    // Test addition
    sumar(A, B, R);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            assert(R[i][j] == 3 * i);
        }
    }

    // Test subtraction
    resta(A, B, R);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            assert(R[i][j] == 2 * j - i);
        }
    }

    // Test scalar multiplication, including a negative scalar
    productoEscalar(A, -2, R);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            assert(R[i][j] == -2 * (i + j));
        }
    }

    // Test matrix multiplication using the identity matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            B[i][j] = (i == j) ? 1 : 0;
        }
    }

    multiplicar(A, B, R);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            assert(R[i][j] == A[i][j]);
        }
    }

    printf("All OPMATRIX tests passed!\n");
    return 0;
}
