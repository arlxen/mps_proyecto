
#ifndef IOMATRIX_H
#define IOMATRIX_H

#include <stdio.h>
#include <time.h>
#include "matrix_types.h"

int guardarMatriz(Matrix matriz, char nombre)
{
    char nombreFichero[256];
    FILE *fichero;

    printf("Enter the filename: ");

    if (scanf("%255s", nombreFichero) != 1)
    {
        printf("[ERROR] Invalid filename.\n");
        return MATRIX_ERROR_FILE_OPEN;
    }

    fichero = fopen(nombreFichero, "w");

    if (fichero == NULL)
    {
        perror("[ERROR] Could not open the file");
        return MATRIX_ERROR_FILE_OPEN;
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (fprintf(fichero, "%.2f%c",
                        matriz[i][j],
                        j == MATRIX_SIZE - 1 ? '\n' : ' ') < 0)
            {
                fclose(fichero);
                printf("[ERROR] Could not write the matrix.\n");
                return MATRIX_ERROR_FILE_WRITE;
            }
        }
    }

    if (fclose(fichero) == EOF)
    {
        printf("[ERROR] Could not close the file correctly.\n");
        return MATRIX_ERROR_FILE_WRITE;
    }

    printf("[OK] Matrix %c saved to %s.\n",
           nombre, nombreFichero);

    registrarLog("SAVE", nombreFichero);

    return MATRIX_OK;
}

int cargarMatriz(Matrix matriz, char nombre)
{
    char nombreFichero[256];
    FILE *fichero;
    Matrix matrizTemporal;

    printf("Enter the filename to load: ");

    if (scanf("%255s", nombreFichero) != 1)
    {
        printf("[ERROR] Invalid filename.\n");
        return MATRIX_ERROR_FILE_OPEN;
    }

    fichero = fopen(nombreFichero, "r");

    if (fichero == NULL)
    {
        perror("[ERROR] Could not open the file");
        return MATRIX_ERROR_FILE_OPEN;
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (fscanf(fichero, "%lf",
                       &matrizTemporal[i][j]) != 1)
            {
                fclose(fichero);
                printf("[ERROR] Invalid file or insufficient data.\n");
                return MATRIX_ERROR_FILE_READ;
            }
        }
    }

    if (fclose(fichero) == EOF)
    {
        printf("[ERROR] Could not close the file correctly.\n");
        return MATRIX_ERROR_FILE_READ;
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matriz[i][j] = matrizTemporal[i][j];
        }
    }

    printf("[OK] Matrix %c loaded from %s.\n",
           nombre, nombreFichero);

    registrarLog("LOAD", nombreFichero);

    return MATRIX_OK;
}

void registrarLog(const char *operacion, const char *detalle)
{
    FILE *log = fopen("log_operaciones.txt", "a");

    if (log == NULL)
    {
        perror("[ERROR] Could not open log file");
        return;
    }

    time_t ahora = time(NULL);
    struct tm *fecha = localtime(&ahora);

    if (fecha != NULL)
    {
        fprintf(log,
                "[%04d-%02d-%02d %02d:%02d:%02d] %s - %s\n",
                fecha->tm_year + 1900,
                fecha->tm_mon + 1,
                fecha->tm_mday,
                fecha->tm_hour,
                fecha->tm_min,
                fecha->tm_sec,
                operacion,
                detalle);
    }
    else
    {
        fprintf(log, "%s - %s\n", operacion, detalle);
    }

    fclose(log);
}

#endif
