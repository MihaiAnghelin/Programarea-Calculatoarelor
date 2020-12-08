#include <stdio.h>

int rmFirst(int a[], int* n)
{
    int first = a[0];

    for (int i = 0; i < *n; i++)
    {
        if(a[i] == first)
        {
            for(int j = i; j < *n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            (*n)--;
        }
    }

    if(a[*n - 1] == first)
        (*n)--;
}

int main()
{
    int a[10], n;

    printf("Cititi numarul de elemente din vector: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    rmFirst(a, &n);

    if(n != 0)
    {
        printf("Elementele ramase in vector sunt: \n");
        for (int i = 0; i < n; i++)
        {
            printf("a[%d] = %d\n", i, a[i]);
        }
    }
    else
    {
        printf("Nu exista elemente ramase in vector\n");
    }
    

    return 0;
}