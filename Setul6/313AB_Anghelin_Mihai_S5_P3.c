#include <stdio.h>

void tip_nr(int v[], int n, int* poz, int* neg, int* nul)
{
    *poz = 0; 
    *neg = 0;
    *nul = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0)
        {
            (*nul)++;
        }
        else if (v[i] < 0)
        {
            (*neg)++;
        }
        else if (v[i] > 0)
        {
            (*poz)++;
        }      
    }
    
}

int main()
{
    int v[10], n, poz, neg, nul;

    printf("Cititi numarul de elemente din vector: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    
    tip_nr(v, n, &poz, &nul, &neg);

    printf("In vector sunt:\n%d elemente pozitive\n%d elemente negative\n%d elemente nule\n", poz, nul, neg);

    return 0;
}