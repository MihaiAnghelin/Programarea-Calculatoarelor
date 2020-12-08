#include <stdio.h>

void elem_com(int a[], int na, int b[], int nb, int c[], int* nc)
{
    *nc = 0;
    int h = 0;


    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if(a[i] == b[j])
            {
                c[h] = a[i];
                h++;
            }
        }
    }
    
    *nc = h;
}


int main()
{
    int a[10], na;
    int b[10], nb;
    int c[10], nc;

    printf("Cititi numarul de elemente din primul vector: ");
    scanf("%d", &na);

    for (int i = 0; i < na; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Cititi numarul de elemente din al doilea vector: ");
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    elem_com(a, na, b, nb, c, &nc);
    
    if(nc != 0)
    {
        printf("Elementele comune din cei doi vectori sunt: ");
        for (int i = 0; i < nc; i++)
        {
            printf("%d ", c[i]);
        }
    }
    else
    {
        printf("Nu exista elemente comune");
    }
    
    printf("\n");
    
    return 0;
}