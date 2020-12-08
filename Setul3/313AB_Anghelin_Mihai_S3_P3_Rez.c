#include <stdio.h>

int main()
{
    int v[20], n, ap, max;

    printf("Introduceti numarul de elemente din vector: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ap = 1;
        for (int j = i + 1; j < n; j++)
        {
            if(v[i] == v[j])
            {
                ap++;
            }
        }

        if(ap > max)
        {
            max = ap;
        }
        
    }

    printf("Elementele urmatoare apar de cele mai multe ori (%d ori) in vector: ", max);
    for (int i = 0; i < n; i++)
    {
        ap = 1;
        for (int j = i + 1; j < n; j++)
        {
            if(v[i] == v[j])
            {
                ap++;
            }
        }

        if(ap == max)
        {
            printf("%d ", v[i]);
        }
    }

    printf("\n");
    return 0;

}