#include <stdio.h>
#include <stdlib.h>

#include "OPMATRIX.h"
#include "OPMATRIX.c"

#include "MATRIX_TYPES.h"


MatrixError pedirMatrizPorPantalla(Matrix matriz, const char *nombre) {
    if (matriz == NULL) {
        return MATRIX_ERROR_NULL;
    }

    printf("\n--- Introducir datos de la Matriz %s (%dx%d) ---\n", nombre, MATRIX_SIZE, MATRIX_SIZE);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("Matriz %s [%d][%d]: ", nombre, i + 1, j + 1);

            // %lf coincide exactamente con MatrixElement (double)
            while (scanf("%lf", &matriz[i][j]) != 1) {
                printf("[ERROR] Valor no valido. Introduce un numero para [%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n'); // Limpiar b�fer de entrada
            }
        }
    }
    printf("\n[OK] Matriz %s introducida correctamente.\n", nombre);
    return MATRIX_OK;
}

// Funci�n para mostrar por pantalla una matriz 5x5 formateada
MatrixError mostrarMatriz(const Matrix matriz, const char *nombre) {
    if (matriz == NULL) {
        return MATRIX_ERROR_NULL;
    }

    printf("\n--- Matriz %s (%dx%d) ---\n", nombre, MATRIX_SIZE, MATRIX_SIZE);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < MATRIX_SIZE; j++) {
            // %8.2lf asigna 8 espacios de ancho y 2 decimales para alinear en tabla
            printf("%8.2lf ", matriz[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------------------------------\n");

    return MATRIX_OK;
}

void visualizar(Matrix A){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            if (j == 0){
                printf("| %3i |", A[i][j]);
            }else{
                printf(" %3i |", A[i][j]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    int opcion = 0;
    int seleccion = 0;

    // Declaraci�n de las matrices usando el typedef 'Matrix'
    Matrix matrizA = {0};
    Matrix matrizB = {0};
    Matrix matrizR = {0}; // Matriz resultado

    do {
        printf("\n========================================\n");
        printf("       GESTOR DE MATRICES (%dx%d)       \n", MATRIX_SIZE, MATRIX_SIZE);
        printf("========================================\n");
        printf("1. Introducir matriz por pantalla (A / B)\n");
        //printf("2. Cargar matriz desde archivo (A / B)\n");
        //printf("3. Guardar matriz en archivo\n");
        printf("2. Mostrar matrices por pantalla\n");
        printf("3. Sumar matrices\n");
        printf("4. Restar matrices\n");
        printf("5. Multiplicar matrices\n");
        //printf("6. Multiplicar por un escalar\n");
        printf("6. Salir\n");
        printf("========================================\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                printf("\n�Que matriz deseas introducir? (1 para Matriz A, 2 para Matriz B): ");
                if (scanf("%d", &seleccion) == 1) {
                    if (seleccion == 1) {
                        pedirMatrizPorPantalla(matrizA, "A");
                    } else if (seleccion == 2) {
                        pedirMatrizPorPantalla(matrizB, "B");
                    } else {
                        printf("\n[ERROR] Seleccion no valida.\n");
                    }
                } else {
                    while (getchar() != '\n');
                }
                break;
            /*case 2:
                printf("\n[INFO] Opcion Cargar matriz desde archivo seleccionada.\n");
                break;
            case 3:
                printf("\n[INFO] Opcion Guardar matriz en archivo seleccionada.\n");
                break;
                */
            case 2:
                printf("\n[INFO] Opcion Mostrar matrices seleccionada.\n");
                mostrarMatriz(matrizA, "A");
                mostrarMatriz(matrizB, "B");
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 3:
                printf("\n[INFO] Opcion SUMA seleccionada.\n");
                sumar(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 4:
                printf("\n[INFO] Opcion RESTA seleccionada.\n");
                resta(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 5:
                printf("\n[INFO] Opcion MULTIPLICACION seleccionada.\n");
                multiplicar(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            /*case 8:
                printf("\n[INFO] Opcion MULTIPLICAR POR UN ESCALAR seleccionada.\n");
                multiplicar(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
                */
            case 6:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\n[ERROR] Opcion no valida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 8);

    return EXIT_SUCCESS;
}
