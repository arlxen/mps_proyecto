#include <stdio.h>
#include <stdlib.h>

#include "MATRIX_TYPES.h"
#include "OPMATRIX.h"
#include "IOMATRIX.h"

MatrixError pedirMatrizPorPantalla(Matrix matriz, const char *nombre)
{
    if (matriz == NULL)
        return MATRIX_ERROR_NULL;

    printf("\n--- Introducir matriz %s ---\n", nombre);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("Matriz %s [%d][%d]: ", nombre, i + 1, j + 1);

            while (scanf("%lf", &matriz[i][j]) != 1)
            {
                printf("[ERROR] Introduce un numero: ");
                while (getchar() != '\n')
                    ;
            }
        }
    }

    return MATRIX_OK;
}

MatrixError mostrarMatriz(const Matrix matriz, const char *nombre)
{
    if (matriz == NULL)
        return MATRIX_ERROR_NULL;

    printf("\n--- Matriz %s ---\n", nombre);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
            printf("%8.2lf ", matriz[i][j]);
        printf("\n");
    }

    return MATRIX_OK;
}

int main(void)
{
    int opcion = 0;
    int seleccion = 0;

    Matrix matrizA = {0};
    Matrix matrizB = {0};
    Matrix matrizR = {0};

    do
    {
        printf("\n========================================\n");
        printf("       GESTOR DE MATRICES (%dx%d)\n", MATRIX_SIZE, MATRIX_SIZE);
        printf("========================================\n");
        printf("1. Introducir matriz (A / B)\n");
        printf("2. Cargar matriz desde archivo (A / B)\n");
        printf("3. Guardar matriz en archivo (A / B)\n");
        printf("4. Mostrar matrices\n");
        printf("5. Sumar matrices\n");
        printf("6. Restar matrices\n");
        printf("7. Multiplicar matrices\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            while (getchar() != '\n')
                ;
            opcion = 0;
            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("Que matriz deseas introducir? (1=A, 2=B): ");

            if (scanf("%d", &seleccion) != 1)
            {
                while (getchar() != '\n')
                    ;
                break;
            }

            if (seleccion == 1)
                pedirMatrizPorPantalla(matrizA, "A");
            else if (seleccion == 2)
                pedirMatrizPorPantalla(matrizB, "B");
            else
                printf("[ERROR] Seleccion no valida.\n");
            break;

        case 2:
            printf("Que matriz deseas cargar? (1=A, 2=B): ");

            if (scanf("%d", &seleccion) != 1)
            {
                while (getchar() != '\n')
                    ;
                break;
            }

            if (seleccion == 1)
                cargarMatriz(matrizA, 'A');
            else if (seleccion == 2)
                cargarMatriz(matrizB, 'B');
            else
                printf("[ERROR] Seleccion no valida.\n");
            break;

        case 3:
            printf("Que matriz deseas guardar? (1=A, 2=B): ");

            if (scanf("%d", &seleccion) != 1)
            {
                while (getchar() != '\n')
                    ;
                break;
            }

            if (seleccion == 1)
                guardarMatriz(matrizA, 'A');
            else if (seleccion == 2)
                guardarMatriz(matrizB, 'B');
            else
                printf("[ERROR] Seleccion no valida.\n");
            break;

        case 4:
            mostrarMatriz(matrizA, "A");
            mostrarMatriz(matrizB, "B");
            mostrarMatriz(matrizR, "Resultado");
            break;

        case 5:
            sumar(matrizA, matrizB, matrizR);
            mostrarMatriz(matrizR, "Suma");
            break;

        case 6:
            resta(matrizA, matrizB, matrizR);
            mostrarMatriz(matrizR, "Resta");
            break;

        case 7:
            multiplicar(matrizA, matrizB, matrizR);
            mostrarMatriz(matrizR, "Multiplicacion");
            break;

        case 8:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("[ERROR] Opcion no valida.\n");
            break;
        }

    } while (opcion != 8);

    return EXIT_SUCCESS;
}