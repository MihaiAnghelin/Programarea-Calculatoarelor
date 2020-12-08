#include <stdio.h>
#include <stdlib.h>

void citire(int *v, int *n)
{
    printf("numarul de elemente este: ");
    scanf("%d", n);

    v = (int*)calloc(*n, sizeof(int));

    for(int i = 0; i < *n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", v + i);
    }
}

int main()
{
    int *v, n;

    citire(v, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", (*v + i));
    }

    printf("\n");
    return 0;
    
}