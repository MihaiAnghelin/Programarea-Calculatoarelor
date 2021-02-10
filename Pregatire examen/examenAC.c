#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

#define numeFisierMagazin "magazin.bin"
#define numeFisierLista "lista.txt"
#define numeFisierBon "bon.bin"

typedef struct ListaCumparaturi
{
    char denumire[50];
    int cantitate;
} ListaCumparaturi;

typedef struct ProdusBon
{
    char denumire[50];
    char numeFirma[50];
    int cantitate;
    float cost;
} ProdusBon;

typedef struct Produs
{
    char numeFirma[50];
    int stoc;
    float pret;
} Produs;

typedef struct TipProdus
{
    char denumire[50];
    int numarProduse; //maxim 20
    Produs lista[20];
} TipProdus;

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
#pragma endregion

int comparator(const void *p, const void *q)
{
    int left = ((Produs *)p)->stoc;
    int right = ((Produs *)q)->stoc;
    return (left - right); // crescator
}

//functie a
void sortList(TipProdus *tipProdus)
{
    qsort((*tipProdus).lista, (*tipProdus).numarProduse, sizeof(Produs), comparator);
}

//functie b
void *searchInFile(char denumire[], int cantitate)
{
    FILE *f;
    if ((f = fopen(numeFisierMagazin, "rb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisierMagazin);
        exit(EXIT_FAILURE);
    }

    TipProdus tmp;
    while ((fread(&tmp, sizeof(TipProdus), 1, f) == 1) && (strcmp(tmp.denumire, denumire) == 1))
    {
    }

    if (strcmp(tmp.denumire, denumire) == 0)
    {
        sortList(&tmp);

        ProdusBon *t;
        bool exists = false;
        float min = FLT_MAX;
        for (int i = 1; i < tmp.numarProduse; i++)
        {
            if (min > tmp.lista[i].pret && tmp.lista[i].stoc >= cantitate)
            {
                min = tmp.lista[i].pret;

                strcpy((*t).denumire, tmp.denumire);
                strcpy((*t).numeFirma, tmp.lista[i].numeFirma);
                (*t).cantitate = cantitate;
                (*t).cost = tmp.lista[i].pret * cantitate;

                exists = true;
            }
        }

        if (exists)
        {
            return t;
        }
    }

    return NULL;
}

int main()
{
    FILE *magazin;

#pragma region Add Data to binary file

    if ((magazin = fopen(numeFisierMagazin, "wb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisierMagazin);
        exit(EXIT_FAILURE);
    }

    TipProdus tipProdus;
    strcpy(tipProdus.denumire, "faina");
    tipProdus.numarProduse = 3;

    strcpy(tipProdus.lista[0].numeFirma, "Dobrogea");
    strcpy(tipProdus.lista[1].numeFirma, "Baneasa");
    strcpy(tipProdus.lista[2].numeFirma, "Titan");

    tipProdus.lista[0].stoc = 30;
    tipProdus.lista[1].stoc = 20;
    tipProdus.lista[2].stoc = 100;

    tipProdus.lista[0].pret = 3.34;
    tipProdus.lista[1].pret = 3.99;
    tipProdus.lista[2].pret = 3.87;

    fwrite(&tipProdus, sizeof(TipProdus), 1, magazin);

    fclose(magazin);

#pragma endregion

#pragma region Read Data from binary file
    if ((magazin = fopen(numeFisierMagazin, "rb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisierMagazin);
        exit(EXIT_FAILURE);
    }

    fseek(magazin, 0L, SEEK_END);
    int numarTipProdus = ftell(magazin) / sizeof(TipProdus);
    fseek(magazin, 0L, SEEK_SET);

    TipProdus *tipuriProduse = malloc(numarTipProdus * sizeof(TipProdus));

    fread(tipuriProduse, sizeof(TipProdus), numarTipProdus, magazin);
    fclose(magazin);
#pragma endregion

#pragma region Print Data from binary file
    // for (int i = 0; i < numarTipProdus; i++)
    // {
    //     printf("%s %d", tipuriProduse[i].denumire,
    //            tipuriProduse[i].numarProduse);
    //     puts("\n");

    //     for (int j = 0; j < tipuriProduse[i].numarProduse; j++)
    //     {
    //         printf("\t%s %d %.2f",
    //                tipuriProduse[i].lista[j].numeFirma,
    //                tipuriProduse[i].lista[j].stoc,
    //                tipuriProduse[i].lista[j].pret);

    //         puts("\n");
    //     }

    //     puts("\n");
    // }
#pragma endregion

#pragma region Read Data for Lista de cumparaturi
    FILE *fisierListaCump;

    if ((fisierListaCump = fopen(numeFisierLista, "rt")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisierLista);
        exit(EXIT_FAILURE);
    }

    ListaCumparaturi listaCumparaturi[30];

    int numarLista = 0;
    while (fscanf(fisierListaCump, "%50s %d", listaCumparaturi[numarLista].denumire, &(listaCumparaturi[numarLista].cantitate)) == 2)
    {
        numarLista++;
    }

#pragma endregion

    FILE *bon;
    if ((bon = fopen(numeFisierBon, "wb")) == NULL)
    {
        printf("Fisierul %s nu poate fi deschis\n", numeFisierBon);
        exit(EXIT_FAILURE);
    }

    float sum = 0;
    Vector produseBon;

    vectorInit(&produseBon, sizeof(ProdusBon));

    for (int i = 0; i < numarLista; i++)
    {
        ProdusBon *item = (ProdusBon *)searchInFile(listaCumparaturi[i].denumire, listaCumparaturi[i].cantitate);

        if (item == NULL)
        {
            int response;
            printf("Produsul %s nu exista in magazin sau exista stoc suficient.\
            \nDoriti sa continuati cu scrierea bonului? (1/0)",
                   listaCumparaturi[i].denumire);
            scanf("%d", &response);

            if (response == 0)
            {
                return 0;
            }
        }
        else
        {
            sum += (*item).cost;
            vectorPushBack(&produseBon, item);
        }
    }

    for (int i = 0; i < produseBon.size; i++)
    {
        ProdusBon *p = (ProdusBon *)vectorGetElement(&produseBon, i);
        printf("%s, %s, %d, %.2f\n", (*p).denumire,
               (*p).numeFirma, (*p).cantitate, (*p).cost);

        fwrite(p, sizeof(ProdusBon), 1, bon);
    }

    printf("\n\nSuma totala: %.2f\n\n", sum);

    return 0;
}
