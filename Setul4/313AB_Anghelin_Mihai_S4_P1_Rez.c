#include <stdio.h>
#include <stdbool.h>

int main()
{
    int nr1, nr2, n;
    bool cresc = 0, descr = 0, cons = 0;
    printf("Introduceti numarul de elemente din sir: ");
    scanf("%d", &n);

    printf("Introduceti numarul 1: ");
    scanf("%d", &nr1);

    printf("Introduceti numarul 1: ");
    scanf("%d", &nr2);

    if(nr1 == nr2){
        cons = 1;
    }
    else if(nr1 > nr2)
    {
        descr = 1;
    }
    else if(nr1 < nr2)
    {
        cresc = 1;
    }

    for (int i = 3; i <= n; i++)
    {
        nr1 = nr2;

        printf("Introduceti numarul %d: ", i);
        scanf("%d", &nr2);

        if(cons){
            if(nr1 != nr2){
                cons = 0;
            }
        }
        else if(descr)
        {
            if(nr1 < nr2){
                descr = 0;
            }
        }
        else if(cresc)
        {
            if(nr1 > nr2){
                cresc = 0;
            }
        }
    }

    if(cresc){
        printf("\nSirul este crescator.\n");
    }
    else if(descr)
    {
        printf("\nSirul este descrescator.\n");
    }
    else if(cons)
    {
        printf("\nSirul este constant.\n");
    }
    else
    {
        printf("\nSirul este oarecare.\n");
    }
    
    return 0;
}