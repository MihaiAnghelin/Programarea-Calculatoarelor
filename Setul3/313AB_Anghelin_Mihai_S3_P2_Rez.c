#include <stdio.h>

int main()
{
    int a[20], n;

    printf("Introduceti numarul de elemente din vector: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int b[20], c[20], j = 0, h = 0, bn = 0, cn = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            b[j++] = a[i];
        }
        else
        {
            c[h++] = a[i];
        }
    }

    printf("Elementele pare sunt: ");

    for (int i = 0; i < j; i++)
    {
        printf("%d ", b[i]);
    }
    
    printf("\nElementele impare sunt: ");

    for (int i = 0; i < h; i++)
    {
        printf("%d ", c[i]);
    }
    
    printf("\n");
    

    return 0;
}