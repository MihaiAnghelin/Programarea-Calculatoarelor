#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NR 256
typedef struct DATA
{
    char car;
    int nrAp;
}DATA;

DATA* constr(DATA v[], const int nr, int *n)
{
    DATA *x;
    x = (DATA*)malloc(32 * sizeof(DATA));
    *n = 0;
    int i, NUMAR;
    printf("Dati numarul: ");
    scanf("%d", &NUMAR);
    for (i = 0; i < nr; i++)
    {
        if (v[i].nrAp < NUMAR)
        {
            x[*n] = v[i];
            (*n)++;
        }
    }
    return x;
}

DATA maxi(DATA data1, DATA data2)
{
    if (data1.nrAp >= data2.nrAp)
        return data1;
    else
        return data2;

}

void histograma(char histo[], DATA v[], int* nr)
{
    int aparitii[MAX_NR] = { 0 };

    for (int i = 0; i < strlen(histo); i++)
    {
        aparitii[histo[i]]++;
    }
    *nr = 0;
    for (int i = 0; i < MAX_NR; i++)
    {
        if (aparitii[i] != 0)
        {
            v[*nr].car = i;
            v[*nr].nrAp = aparitii[i];
            (*nr)++;
        }
    }

    for (int i = 0; i < *nr; i++)
        printf("{%c,%d}  ", v[i].car, v[i].nrAp);

    printf("\n");
}

void main()
{
    char histo[MAX_NR];
    DATA data[MAX_NR];
    int nr;

    printf("Introduceti sirul: ");
    scanf("%s", histo);
    histograma(histo, data, &nr);

    DATA* x;
    int n;
    x = constr(data, nr, &n);
    for(int i = 0; i < n; i++)
        printf("%c ", x[i].car);

    DATA d = maxi(data[0], data[1]);
    printf("\n\n%c %d\n\n", d.car, d.nrAp);
}