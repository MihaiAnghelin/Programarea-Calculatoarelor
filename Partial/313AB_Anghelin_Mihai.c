// 313AB, Anghelin Mihai

#include <stdio.h>
#include <stdlib.h>

void citire(float **v, int *n)
{
    printf("Numarul de burse este: ");
    scanf("%d", n);

    *v = (float*)calloc(*n, sizeof(float));

    for(int i = 0; i < *n; i++)
    {
        printf("bursa[%d] = ", i);
        scanf("%f", (*v) + i);
    }
}

void extindere(float *v, int *n)
{
    v = realloc(v, (*n) + 2);
    
    //citire valori noi

    printf("Penultimul student: ");
    scanf("%f", (v + (*n)));

    printf("Ultimul student: ");
    scanf("%f", (v + (*n) + 1));

    (*n) += 2;
}

int main()
{
    float *burse;
    int numar_burse;

    citire(&burse, &numar_burse);

    for (int i = 0; i < numar_burse; i++)
    {
        printf("%f ", burse[i]);
    }

    printf("\n");

    extindere(burse, &numar_burse);

    for (int i = 0; i < numar_burse; i++)
    {
        printf("%f ", burse[i]);
    }

    printf("\n");

    int nr_burse_mari = 0;
    for (int i = 0; i < numar_burse; i++)
    {
        if(burse[i] > 9.5)
            nr_burse_mari++;
    }

    printf("Numarul de burse peste 9.5 este: %d\n", nr_burse_mari);
    
    return 0;
}