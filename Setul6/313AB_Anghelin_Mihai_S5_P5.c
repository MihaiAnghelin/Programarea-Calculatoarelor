#include <stdio.h>
#include <limits.h>

void min(int a[], int na, int b[], int* nb)
{
    int m = INT_MAX;
    for (int i = 0; i < na; i++)
    {
        if(a[i] < m)
            m = a[i];
    }

    *nb = 0;
    for (int i = 0; i < na; i++)
    {
        if(a[i] == m)
            b[(*nb)++] = a[i];
    }
}

int main()
{
    int a[10], na;
    int b[10], nb;

    printf("Cititi numarul de elemente din vector: ");
    scanf("%d", &na);

    for (int i = 0; i < na; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    min(a, na, b, &nb);

    printf("Elementele minime in vectorul a sunt: \n");
    for (int i = 0; i < nb; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}