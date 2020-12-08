#include <stdio.h>

void ex1()
{
    
}

int main()
{
    printf("\n\n // Exercitiul 1: //\n");
    int n, v[30];

    printf("Cititi numarul de elemente din vector: ");
    scanf("%d", &n);

    printf("\nCititi elementele vectorului: \n");

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("\n\n subpunctul a): \n\n");

    int prag;
    printf("Cititi un prag (numar întreg): ");
    scanf("%d", &prag);

    printf("\nValorile ce depasesc pragul si pozitiile acestora sunt: \n");
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > prag)
        {
            printf("v[%d] = %d\n", i, v[i]);
            ok = 1;
        }
    }
    if(!ok){
        printf("Nu exista niciun element mai mare decat pragul!\n");
    }

    printf("\n\n subpunctul b): \n\n");

    printf("Valorile ce se afla pe pozitii pare sunt: \n");

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            printf("v[%d] = %d\n", i, v[i]);
        }
    }

    printf("\n\n subpunctul c): \n\n");

    printf("Valorile din vector cu elementele nule eliminate sunt: \n");

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == 0)
        {
            for (int j = i; j < n - 1; j++)
                v[j] = v[j + 1];
            n--;
            i--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n\n subpunctul d): \n\n");

    printf("Elementele din vector inlocuite cu numarul lor de divizori sunt: \n");

    for (int i = 0; i < n - 1; i++)
    {
        int nrDiv = 2;

        for (int div = 2; div <= n / 2; div++)
        {
            if (v[i] % div == 0)
                nrDiv++;
        }

        v[i] = nrDiv;

        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}