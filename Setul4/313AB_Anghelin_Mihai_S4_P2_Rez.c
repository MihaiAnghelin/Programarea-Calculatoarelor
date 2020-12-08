#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int v[30], n, min = INT_MAX;
    float med = 0;

    printf("Introduceti numarul de elemente din sir: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Introduceti v[%d]: ", i);
        scanf("%d", &v[i]);

        if(v[i] < min){
            min = v[i];
        }

        med += v[i];
    }

    med /= n;

    bool ok = false;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == med)
            ok = true;
    }

    if(ok)
    {
        printf("\nValoarea medie este %0.2f si apartine vectorului\n", med);
    }
    else
    {
        printf("\nValoarea medie este %0.2f si nu apartine vectorului\n", med);
    }

    printf("\nValoarea minima din vector este: %d\n", min);
    
    return 0;
    
}