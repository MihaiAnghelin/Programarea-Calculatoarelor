#include <stdio.h>
#include <math.h>
#define cerc 'c'
#define patrat 'p'
#define drepunghi 'd'

struct Dreptunghi
{
    int lung;
    int lat;
};

union Dimensiune
{
    int raza;
    int lat;
    struct Dreptunghi dim;
};

struct FiguraGeometrica
{
    char nume;
    char tip;
    union Dimensiune dimensiune;
};



int main()
{
    struct FiguraGeometrica figura;
    printf("Alegeti tipul figurii (c = cerc, p = patrat, d = dreptunghi): ");
    figura.tip = getchar();

    while(figura.tip != cerc && figura.tip != patrat && figura.tip != drepunghi)
    {
        printf("\nCitirea a fost gresita! Reintroduceti datele!\n");
        printf("Alegeti tipul figurii (c = cerc, p = patrat, d = dreptunghi): ");
        scanf("%c", &figura.tip);
    }

    float perimetru, arie;

    switch (figura.tip)
    {   
    case cerc:
        printf("Introduceti raza cercului: ");
        scanf("%d", &figura.dimensiune.raza);

        perimetru = 2 * M_PI * figura.dimensiune.raza;
        arie = M_PI * figura.dimensiune.raza * figura.dimensiune.raza;
        break;

    case patrat:
        printf("Introduceti lungimea laturii patratului: ");
        scanf("%d", &figura.dimensiune.lat);

        perimetru = 4 * figura.dimensiune.lat;
        arie = figura.dimensiune.lat * figura.dimensiune.lat;
        break;
        
    case drepunghi:
        printf("Introduceti lungimea dreptunghiului: ");
        scanf("%d", &figura.dimensiune.dim.lung);

        printf("Introduceti latimea dreptunghiului: ");
        scanf("%d", &figura.dimensiune.dim.lat);

        perimetru = 2 * figura.dimensiune.dim.lat + 2 * figura.dimensiune.dim.lung;
        arie = figura.dimensiune.dim.lung * figura.dimensiune.dim.lat;
        break;
    }

    printf("\nPerimetrul figurii este: %.2f\n", perimetru);
    printf("Aria figurii este: %.2f\n", arie);

    return 0;
}