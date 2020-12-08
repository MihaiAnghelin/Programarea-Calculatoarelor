#include <stdio.h>

void ex1()
{
    char input;

    printf("Introduceti un caracter de la tastatura: ");
    scanf("%c", &input);

    if (input >= 'A' && input <= 'Z')
    {
        printf("Caracterul este o litera mare");
    }
    else if (input >= 'a' && input <= 'z')
    {
        printf("Caracterul este o litera mica");
    }
    else if (input >= '0' && input <= '9')
    {
        printf("Caracterul este o cifra");
    }
    else
    {
        printf("Caracterul este un caracter special");
    }
}

void ex3()
{
    int number, ok = 1;

    printf("Introduceti un numar natural: ");
    scanf("%d", &number);

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            ok = 0;
            break;
        }
    }

    if (ok)
    {
        printf("Numarul este prim");
    }
    else
    {
        printf("Numarul NU este prim");
    }
}

void ex6_intreg()
{
    int number, poz = 0, neg = 0;

    printf("Introduceti numere diferite de 0 (citirea se opreste la introducerea valorii 0): \n");
    scanf("%d", &number);

    while (number != 0)
    {
        if (number > 0)
        {
            poz++;
        }
        else
        {
            neg++;
        }

        scanf("%d", &number);
    }

    printf("Au fost introduse %d valori pozitive si %d valori negative.", poz, neg);
}

void ex6_real()
{
    int poz = 0, neg = 0;
    float number;

    printf("Introduceti numere diferite de 0 (citirea se opreste la introducerea valorii 0): \n");
    scanf("%f", &number);

    while (number != 0)
    {
        if (number > 0)
        {
            poz++;
        }
        else if (number < 0)
        {
            neg++;
        }

        scanf("%f", &number);
    }

    printf("Au fost introduse %d valori pozitive si %d valori negative.", poz, neg);
}

void ex9()
{
    int n, p = 0;

    printf("Introduceti un numar natural: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a = 1;
        for (int j = 2; j <= i; j++)
        {
            a *= j;
        }
        p += a;
    }

    printf("Suma S este %d", p);
}

int main()
{
    printf("\n\n // Exercitiul 1: //\n");
    ex1();

    printf("\n\n // Exercitiul 3: //\n");
    ex3();

    printf("\n\n // Exercitiul 6 pt cazul intreg: //\n");
    ex6_intreg();

    printf("\n\n // Exercitiul 6 pt cazul real: //\n");
    ex6_real();

    printf("\n\n // Exercitiul 9: //\n");
    ex9();

    printf("\n");

    return 0;
}