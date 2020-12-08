#include <stdio.h>

char ordine(int a, int b, int c)
{
    if (a < b && b < c)
    {
        return 'C';
    }
    else if(a > b && b > c)
    {
        return 'D';
    }
    else if(a == b && a == c)
    {
        return 'I';
    }
    else
    {
        return 'N';
    }
}

int main()
{
    int a, b, c, rasp;

    do
    {
        printf("Cititi primul numar: ");
        scanf("%d", &a);


        printf("Cititi al doilea numar: ");
        scanf("%d", &b);


        printf("Cititi al treilea numar: ");
        scanf("%d", &c);

        if(ordine(a, b, c) == 'C')
            printf("Numerele sunt in ordine crescatoare\n");
        else if(ordine(a, b, c) == 'D')
            printf("Numerele sunt in ordine descrescatoare\n");
        else if(ordine(a, b, c) == 'I')
            printf("Numerele sunt identice\n");
        else if(ordine(a, b, c) == 'N')
            printf("Numerele nu sunt in ordine\n");
    
        printf("\nMai doriti sa rulati inca odata programul? (1/0) ");
        scanf("%d", &rasp);

    }while(rasp);
    
    printf("\nExecutia programului s-a incheiat\n");

    return 0;
}