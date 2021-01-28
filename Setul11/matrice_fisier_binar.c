#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *initializeDynamicMatrix(int *lines, int *columns)
{
    int *matrix;

    printf("Introduceti numarul de linii: ");
    scanf("%d", lines);

    printf("Introduceti numarul de coloane: ");
    scanf("%d", columns);

    matrix = (int *)malloc((*lines) * (*columns) * sizeof(int));

    for (int i = 0; i < (*lines); i++)
    {
        for (int j = 0; j < (*columns); j++)
        {
            printf("Matrice[%d][%d]: \t", i, j);
            scanf("%d", &matrix[i * (*columns) + j]);
        }
    }

    return matrix;
}

int pr = 0;
void printMatrix(int *matrix, int lines, int columns)
{
    printf("\nPrint %d\n", pr++);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", matrix[i * columns + j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

void clearMatrix(int *matrix, int *lines, int *colums)
{
    free(matrix);
    *lines = 0;
    *colums = 0;
}

void main()
{
    char fileName[50];
    strcpy(fileName, "fisierBinar.bin");

    FILE *file;
    int lines, columns, *matrix;

    matrix = initializeDynamicMatrix(&lines, &columns);
    printMatrix(matrix, lines, columns);

#pragma region WriteBinary

    if ((file = fopen(fileName, "wb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis \n", fileName);
        exit(EXIT_FAILURE);
    }

    fwrite(&lines, sizeof(lines), 1, file);
    fwrite(&columns, sizeof(columns), 1, file);
    fwrite(matrix, sizeof(int), lines * columns, file);

#pragma endregion

    fclose(file);
    clearMatrix(matrix, &lines, &columns);

#pragma region ReadBinary

    if ((file = fopen(fileName, "rb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis \n", fileName);
        exit(EXIT_FAILURE);
    }

    fread(&lines, sizeof(lines), 1, file);
    fread(&columns, sizeof(columns), 1, file);
    fread(matrix, sizeof(int), lines * columns, file);

#pragma endregion

    printMatrix(matrix, lines, columns);

    fclose(file);
    exit(EXIT_SUCCESS);
}