// 313AB, Anghelin Mihai

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#pragma region Vector

typedef struct Vector
{
    void *begin;
    size_t size;
    size_t capacity;
    size_t itemSize;
} Vector;

void vectorInit(Vector *v, size_t size)
{
    v->begin = 0;
    v->size = 0;
    v->capacity = 0;
    v->itemSize = size;
}

void vectorPushBack(Vector *v, void *el)
{
    if (v->capacity == 0) //init arena
    {
        const int beginElements = 2;

        v->begin = calloc(beginElements, v->itemSize);
        v->capacity = beginElements;
        v->size = 0;
    }

    if (v->capacity == v->size) //resize
    {
        void *newBegin = calloc(v->capacity * 2, v->itemSize);

        memcpy(newBegin, v->begin, v->capacity * v->itemSize);

        free(v->begin);
        v->begin = newBegin;
        v->capacity *= 2;
    }

    //apend at end
    memcpy(((char *)v->begin) + v->itemSize * v->size, el, v->itemSize);

    v->size++;
}

void *vectorGetElement(Vector *v, size_t i)
{
    return ((char *)v->begin) + v->itemSize * i;
}

void vectorSwap(Vector *vec, int i, int j)
{
    void *v = malloc(vec->itemSize);
    memcpy(v, vectorGetElement(vec, i), vec->itemSize);
    memcpy(vectorGetElement(vec, i), vectorGetElement(vec, j), vec->itemSize);
    memcpy(vectorGetElement(vec, j), v, vec->itemSize);
    free(v);
}

#pragma endregion

typedef struct Masina
{
    char numeProprietar[50];
    char numarInmatriculare[11];
    int zi, luna, an;
} Masina;

//Adevarat daca exista proprietari cu mai multe masini, altfel fals
bool functie1(int an, char judet[], Vector *masini, Vector *masiniPrev)
{
    Vector masiniPrevazute;
    vectorInit(&masiniPrevazute, sizeof(Masina));

    for (int i = 0; i < masini->size; i++)
    {
        Masina *m = (Masina *)vectorGetElement(masini, i);
        char *judetCurent;

        strncpy(judetCurent, (*m).numarInmatriculare, 2);

        if (((*m).an == an) && (strcmp(judetCurent, judet) == 0))
        {
            vectorPushBack(&masiniPrevazute, m);
        }
    }
    bool exista = false;
    for (int i = 0; i < masiniPrev->size; i++)
    {
        Masina *m1 = (Masina *)vectorGetElement(&masiniPrevazute, i);
        for (int j = i + 1; j < masini->size; j++)
        {
            Masina *m2 = (Masina *)vectorGetElement(&masiniPrevazute, j);
            if (strcmp((*m1).numeProprietar, (*m2).numeProprietar) == 0)
            {
                exista = true;
            }
        }
    }

    masiniPrev = &masiniPrevazute;

    return exista;
}

int comparator(const void *p, const void *q)
{
    int left = (((Masina *)p)->luna) * 100 + ((Masina *)p)->zi;
    int right = (((Masina *)q)->luna) * 100 + ((Masina *)q)->zi;

    return (left - right); //crescator
}

void functie2(Vector *masiniPrev)
{
    //verifica ordonare
    bool ordonat = true;
    for (int i = 0; i < masiniPrev->size; i++)
    {
        Masina *m1 = (Masina *)vectorGetElement(masiniPrev, i);
        Masina *m2 = (Masina *)vectorGetElement(masiniPrev, i + 1);

        if ((*m1).luna < (*m2).luna)
        {
            if ((*m1).zi < (*m2).zi)
                ordonat = false;
            break;
        }
    }

    //ordoneaza
    if (!ordonat)
    {
        for (int i = 0; i < masiniPrev->size - 1; i++)
        {
            Masina *m1 = (Masina *)vectorGetElement(masiniPrev, i);

            for (int j = i; j < masiniPrev->size - 1; j++)
            {
                Masina *m2 = (Masina *)vectorGetElement(masiniPrev, j);

                if (comparator(m1, m2) >= 0)
                {
                    vectorSwap(masiniPrev, i, j);
                }
            }
        }
    }

    //scrie in fisier
    FILE *file;
    char fileName[50];
    strcpy(fileName, "fisier.txt");

    if ((file = fopen(fileName, "wt")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", fileName);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < masiniPrev->size; i++)
    {
        Masina *m = (Masina *)vectorGetElement(masiniPrev, i);

        fprintf(file, "%s %d %d %d\n", (*m).numarInmatriculare, (*m).zi, (*m).luna, (*m).an);
    }

    fclose(file);
}

int main()
{

#pragma region Citire Fisier
    FILE *fisier;
    char numeFisier[50];
    strcpy(numeFisier, "masini.bin");

    if ((fisier = fopen(numeFisier, "rb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisier);
        exit(EXIT_FAILURE);
    }

    fseek(fisier, 0L, SEEK_END);
    int numarMasini = ftell(fisier) / sizeof(Masina);
    fseek(fisier, 0L, SEEK_SET);

    Vector masini;
    vectorInit(&masini, sizeof(Masina));

    for (int i = 0; i < numarMasini; i++)
    {
        Masina *m;
        fread(m, sizeof(Masina), 1, fisier);
        vectorPushBack(&masini, &m);
    }

    fclose(fisier);
#pragma endregion

    int an;
    char judet[2];
    printf("Introduceti anul: ");
    scanf("%d", &an);

    printf("Intoduceti judetul: ");
    scanf("%s", judet);

    Vector masiniPrevazute;

    //numarul de masini prevazute este masiniPrevazute.size
    if (functie1(an, judet, &masini, &masiniPrevazute))
    {
        printf("Exista cel putin un proprietar care detine\
         mai multe autoturisme pentru datele introduse");
    }

    functie2(&masiniPrevazute);

    int luna;
    printf("Introduceti o luna: ");
    scanf("%d", &luna);

#pragma region Citire din fisier text
    FILE *file;
    char fileName[50];
    strcpy(fileName, "fisier.txt");

    if ((file = fopen(fileName, "rt")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", fileName);
        exit(EXIT_FAILURE);
    }

    char n[12];
    int z, l, a;
    while (fscanf(file, "%s %d %d %d", n, &z, &l, &a))
    {
        if (l == luna)
        {
            printf("%s %d.%d.%d\n", n, z, l, a);
        }
    }
#pragma endregion

    return 0;
}