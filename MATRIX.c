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
                while (getchar() != '\n'); // Limpiar búfer de entrada
            }
        }
    }
    printf("\n[OK] Matriz %s introducida correctamente.\n", nombre);
    return MATRIX_OK;
}

// Función para mostrar por pantalla una matriz 5x5 formateada
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

    // Declaración de las matrices usando el typedef 'Matrix'
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
        printf("4. Mostrar matrices por pantalla\n");
        printf("5. Sumar matrices\n");
        printf("6. Restar matrices\n");
        printf("7. Multiplicar matrices\n");
        printf("8. Multiplicar por un escalar\n");
        printf("9. Matriz simetrica\n");
        printf("10. Salir\n");
        printf("========================================\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                printf("\n¿Que matriz deseas introducir? (1 para Matriz A, 2 para Matriz B): ");
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
                /*
            case 2: {
                int seleccionMatriz = 0;
                printf("\n[INFO] Opcion Cargar matriz desde archivo seleccionada.\n");
                printf("¿En que matriz deseas cargar los datos? (1 para Matriz A, 2 para Matriz B): ");

                if (scanf("%d", &seleccionMatriz) == 1) {
                    if (seleccionMatriz == 1) {
                        cargarMatriz(matrizA, 'A');
                    } else if (seleccionMatriz == 2) {
                        cargarMatriz(matrizB, 'B');
                    } else {
                        printf("\n[ERROR] Seleccion de matriz no valida.\n");
                    }
                } else {
                    while (getchar() != '\n'); // Limpiar búfer
                    printf("\n[ERROR] Opcion no valida.\n");
                }
                break;
            }
            case 3: {
                int seleccionMatriz = 0;
                printf("\n[INFO] Opcion Guardar matriz en archivo seleccionada.\n");
                printf("¿Que matriz deseas guardar? (1 para Matriz A, 2 para Matriz B, 3 para Matriz Resultado): ");

                if (scanf("%d", &seleccionMatriz) == 1) {
                    if (seleccionMatriz == 1) {
                        guardarMatriz(matrizA, 'A');
                    } else if (seleccionMatriz == 2) {
                        guardarMatriz(matrizB, 'B');
                    } else if (seleccionMatriz == 3) {
                        guardarMatriz(matrizR, 'R');
                    } else {
                        printf("\n[ERROR] Seleccion de matriz no valida.\n");
                    }
                } else {
                    while (getchar() != '\n'); // Limpiar búfer
                    printf("\n[ERROR] Opcion no valida.\n");
                }
                break;
            }
            */
            case 4:
                printf("\n[INFO] Opcion Mostrar matrices seleccionada.\n");
                mostrarMatriz(matrizA, "A");
                mostrarMatriz(matrizB, "B");
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 5:
                printf("\n[INFO] Opcion SUMA seleccionada.\n");
                sumar(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 6:
                printf("\n[INFO] Opcion RESTA seleccionada.\n");
                resta(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 7:
                printf("\n[INFO] Opcion MULTIPLICACION seleccionada.\n");
                multiplicar(matrizA, matrizB, matrizR);
                mostrarMatriz(matrizR, "Resultado (R)");
                break;
            case 8: {
                int k = 0;
                int seleccionMatriz = 0;

                printf("\n[INFO] Opcion PRODUCTO ESCALAR seleccionada.\n");
                printf("¿Que matriz deseas multiplicar? (1 para Matriz A, 2 para Matriz B): ");

                if (scanf("%d", &seleccionMatriz) == 1 && (seleccionMatriz == 1 || seleccionMatriz == 2)) {
                    printf("Introduce el valor del escalar (k): ");

                    if (scanf("%d", &k) == 1) {
                        if (seleccionMatriz == 1) {
                            productoEscalar(matrizA, k, matrizR);
                            mostrarMatriz(matrizR, "Resultado (R = k * A)");
                        } else {
                            productoEscalar(matrizB, k, matrizR);
                            mostrarMatriz(matrizR, "Resultado (R = k * B)");
                        }
                    } else {
                        while (getchar() != '\n'); // Limpiar búfer
                        printf("\n[ERROR] Escalar invalido.\n");
                    }
                } else {
                    while (getchar() != '\n'); // Limpiar búfer si meten opción no válida o carácter
                    printf("\n[ERROR] Seleccion de matriz no valida.\n");
                }
                break;
            }
            /*
            case 9: {
                int seleccionMatriz = 0;
                printf("\n[INFO] Opcion MATRIZ SIMÉTRICA seleccionada.\n");
                printf("¿Que matriz deseas evaluar? (1 para Matriz A, 2 para Matriz B): ");

                if (scanf("%d", &seleccionMatriz) == 1) {
                    int resultado = 0;

                    if (seleccionMatriz == 1) {
                        resultado = esSimetrica(matrizA);
                        printf("\n--- Evaluacion de Matriz A ---\n");
                    } else if (seleccionMatriz == 2) {
                        resultado = esSimetrica(matrizB);
                        printf("\n--- Evaluacion de Matriz B ---\n");
                    } else {
                        printf("\n[ERROR] Seleccion de matriz no valida.\n");
                        break;
                    }

                    if (resultado == 1) {
                        printf("[RESULTADO] La matriz ES simetrica.\n");
                    } else if (resultado == 0) {
                        printf("[RESULTADO] La matriz NO es simetrica.\n");
                    } else {
                        printf("[ERROR] La matriz proporcionada es nula.\n");
                    }

                } else {
                    while (getchar() != '\n'); // Limpiar búfer en caso de entrada no numérica
                    printf("\n[ERROR] Opcion no valida.\n");
                }
                break;
            }
            */
            case 10:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\n[ERROR] Opcion no valida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 10);

    return EXIT_SUCCESS;
}
