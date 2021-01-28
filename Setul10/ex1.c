#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LENGTH 200

int main(void)
{
    char str[STR_LENGTH], fileName[50];
    strcpy(fileName, "ex1.txt");

    printf("Introduceti sirul de caractere (propozitia): ");
    fgets(str, STR_LENGTH, stdin);

    FILE *file;

    if ((file = fopen(fileName, "wt")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis \n", fileName);
        exit(EXIT_FAILURE);
    }

    //Scrie in fisier tot odata
    fprintf(file, "%s", str);

    //Scrie in fisier caracter cu caracter
    for(int i = 0; str[i] != '\0'; i++)
    {
        fprintf(file, "%c", str[i]);
    }

    //Scrie in fisier cuvant cu cuvant pe aceeasi linie
    char cstr[STR_LENGTH];
    strcpy(cstr, str);
    char *p = strtok(cstr, " ");

    while (p)
    {
        fprintf(file, "%s", p);
        p = strtok(NULL, " ");
        
        if(p != NULL)
        {
            fprintf(file, " ");
        }
    }

    //Scrie in fisier cuvant cu cuvant pe linii diferite
    p = strtok(str, " ");

    while (p)
    {
        fprintf(file, "%s", p);
        p = strtok(NULL, " ");

        if(p != NULL)
        {
            fprintf(file, "\n");
        }
    }
    
    fclose(file);

    //Afisare caracter cu caracter
    puts("\nAfisare caracter cu caracter: \n");
    file = fopen(fileName, "rt");
    char ch = getc(file);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(file);        
    }
    

    //Afisare cuvant cu cuvant
    puts("\nAfisare cuvant cu cuvant: \n");
    file = fopen(fileName, "rt");

    char word[50];
    while (fscanf(file, "%50s", word) == 1)
    {
        printf("%s ", word);
    }

    //Afisare linie intreaga
    puts("\n\nAfisare linie cu linie: \n");

    file = fopen(fileName, "rt");

    while (fgets(str, STR_LENGTH, file))
    {
        printf("%s", str);
    }

    char word2[50];

    printf("Introduceti cuvantul ce doriti sa fie inlocuit: ");
    scanf("%s", word);

    printf("Introduceti noul cuvant: ");
    scanf("%s", word2);

    fclose(file);
    exit(EXIT_SUCCESS);
}