
#ifndef IOMATRIX_H
#define IOMATRIX_H

#include <stdio.h>

#define FILAS 5
#define COLUMNAS 5


int guardarMatriz(float matriz[FILAS][COLUMNAS], char nombre)
{
    char nombreFichero[256];
    FILE *fichero;

    printf("Enter the filename: ");

    if (scanf("%255s", nombreFichero) != 1)
    {
        printf("[ERROR] Invalid filename.\n");
        return 0;
    }

    fichero = fopen(nombreFichero, "w");

    if (fichero == NULL)
    {
        perror("[ERROR] Could not open the file");
        return 0;
    }

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (fprintf(fichero, "%.2f%c",
                        matriz[i][j],
                        j == COLUMNAS - 1 ? '\n' : ' ') < 0)
            {
                fclose(fichero);
                printf("[ERROR] Could not write the matrix.\n");
                return 0;
            }
        }
    }

    if (fclose(fichero) == EOF)
    {
        printf("[ERROR] Could not close the file correctly.\n");
        return 0;
    }

    printf("[OK] Matrix %c saved to %s.\n",
           nombre, nombreFichero);

    return 1;
}


int cargarMatriz(float matriz[FILAS][COLUMNAS], char nombre)
{
    char nombreFichero[256];
    FILE *fichero;
    float matrizTemporal[FILAS][COLUMNAS];

    printf("Enter the filename to load: ");

    if (scanf("%255s", nombreFichero) != 1)
    {
        printf("[ERROR] Invalid filename.\n");
        return 0;
    }

    fichero = fopen(nombreFichero, "r");

    if (fichero == NULL)
    {
        perror("[ERROR] Could not open the file");
        return 0;
    }

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (fscanf(fichero, "%f",
                       &matrizTemporal[i][j]) != 1)
            {
                fclose(fichero);
                printf("[ERROR] Invalid file or insufficient data.\n");
                return 0;
            }
        }
    }

    if (fclose(fichero) == EOF)
    {
        printf("[ERROR] Could not close the file correctly.\n");
        return 0;
    }

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j] = matrizTemporal[i][j];
        }
    }

    printf("[OK] Matrix %c loaded from %s.\n",
           nombre, nombreFichero);

    return 1;
}

void registrarLog(const char *operacion, const char *detalle)
{
    FILE *log;
    log = fopen("log_operaciones.txt", "a");

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