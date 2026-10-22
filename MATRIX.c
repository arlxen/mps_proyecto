#include <stdio.h>
#include <stdlib.h>
//#include <OPMATRIX.h>
#include"MATRIX_TYPES.h"

#define FILAS 5
#define COLUMNAS 5

// Funci�n auxiliar para leer una matriz 5x5 por consola
void pedirMatrizPorPantalla(float matriz[FILAS][COLUMNAS], char nombre) {
    printf("\n--- Introducir datos de la Matriz %c (%dx%d) ---\n", nombre, FILAS, COLUMNAS);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Matriz %c [%d][%d]: ", nombre, i + 1, j + 1);
            while (scanf("%f", &matriz[i][j]) != 1) {
                printf("[ERROR] Valor no valido. Introduce un numero para [%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n'); // Limpiar b�fer
            }
        }
    }
    printf("\n[OK] Matriz %c introducida correctamente.\n", nombre);
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

    // Se definen las dos matrices de entrada A y B
    float matrizA[FILAS][COLUMNAS] = {0};
    float matrizB[FILAS][COLUMNAS] = {0};

    do {
        printf("\n========================================\n");
        printf("       GESTOR DE MATRICES (5x5)         \n");
        printf("========================================\n");
        printf("1. Introducir matriz por pantalla (A / B)\n");
        //printf("2. Cargar matriz desde archivo (A / B)\n");
        //printf("3. Guardar matriz en archivo\n");
        //printf("4. Mostrar matrices por pantalla\n");
        //printf("5. Sumar matrices\n");
        //printf("5. Restar matrices\n");
        //printf("5. Multiplicar matrices\n");
        printf("2. Salir\n");
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
                        pedirMatrizPorPantalla(matrizA, 'A');
                    } else if (seleccion == 2) {
                        pedirMatrizPorPantalla(matrizB, 'B');
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

            case 2:
                printf("\n[INFO] Opcion Mostrar matrices seleccionada.\n");
                break;
            /*case 5:
                printf("\n[INFO] Opcion Operaciones seleccionada.\n");
                break;
                */
            case 2:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\n[ERROR] Opcion no valida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 2);

    return EXIT_SUCCESS;
}
