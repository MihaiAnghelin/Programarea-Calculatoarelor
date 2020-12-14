//313AB, Anghelin Mihai

#include <stdio.h>
#include <string.h>

typedef struct participant
{
    char nume[30];
    char localitate[30];
    int cod;
} participant;

void citire(participant participanti[], int *nr)
{
    printf("Introduceti numarul de participanti: ");
    scanf("%d", nr);

    printf("Introduceti datele participantilor:\n");
    for (int i = 0; i < *nr; i++)
    {
        printf("Introduceti numele participantului %d: ", i + 1);
        scanf("%s", participanti[i].nume);
        printf("Introduceti localitatea participantului %d: ", i + 1);
        scanf("%s", participanti[i].localitate);
        printf("Introduceti Codul Unic de Identificare pentru Entitatea preferata a participantului %d: ", i + 1);
        scanf("%d", &participanti[i].cod);
    }
}

int simpatie(participant participanti[], int nr)
{
    int numarCazuri = 0;
    for (int i = 0; i < nr; i++)
    {
        printf("\n");
        int first = 1;
        for (int j = i + 1; j < nr; j++)
        {
            if (strcmp(participanti[i].nume, participanti[j].nume) == 0 && strcmp(participanti[i].localitate, participanti[j].localitate) == 0)
            {
                numarCazuri++;
                if (first)
                {
                    printf("Participantul %s din localitatea %s prefera entitatea %d.\n", participanti[i].nume, participanti[i].localitate, participanti[i].cod);
                    first = 0;
                }
                printf("Participantul %s din localitatea %s prefera entitatea %d.\n", participanti[j].nume, participanti[j].localitate, participanti[j].cod);
                for (int h = j; h < nr; h++)
                {
                    participanti[h] = participanti[h + 1];
                }
                j--;
                nr--;
            }
        }
    }

    return numarCazuri;
}

void popularitate(participant participanti[], int nr)
{
    int frec[100] = {0};
    for (int i = 0; i < nr; i++)
    {
        frec[participanti[i].cod]++;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (frec[j] < frec[j + 1])
            {
                frec[j] = frec[j + 1];
            }
        }
    }

    printf("Cele mai populare 3 sunt:");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", frec[i]);
    }
    
}

int main()
{
    participant participanti[50];
    int nr;

    citire(participanti, &nr);

    printf("\n");
    for (int i = 0; i < nr; i++)
    {
        printf("numele participantului %d: %s\n", i + 1, participanti[i].nume);
        printf("localitatea participantului %d: %s\n", i + 1, participanti[i].localitate);
        printf("Codul Unic de Identificare pentru Entitatea preferata a participantului %d: %d\n", i + 1, participanti[i].cod);
    }

    printf("\n\nNumar situatii: %d\n", simpatie(participanti, nr));

    popularitate(participanti, nr);
    return 0;
}