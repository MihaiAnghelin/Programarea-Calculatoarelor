#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char* toUpper(char *a, char *b, char *c)
{
    bool oka = false, okb = false, okc = false;

    if(*a >= 'a' && *a <= 'z')
    {   
        oka = true;
        *a -= 32;
    }

    if(*b >= 'a' && *b <= 'z')
    {   
        okb = true;
        *b -= 32;
    }

    if(*c >= 'a' && *c <= 'z')
    {   
        okc = true;
        *c -= 32;
    }

    static char str[256] = {};

    if(!oka)
    {
        strcat(str, "Primul caracter nu poate fi transformat.\n");
    }
    if(!okb)
    {
        strcat(str, "Al doilea caracter nu poate fi transformat.\n");
    }
    if(!okc)
    {
        strcat(str, "Al treilea caracter nu poate fi transformat.\n");
    }

    return str;
}


int main()
{
    char a, b, c;

    printf("Cititi primul caracter: ");
    scanf(" %c", &a);


    printf("Cititi al doilea caracter: ");
    scanf(" %c", &b);


    printf("Cititi al treilea caracter: ");
    scanf(" %c", &c);


    const char* str = toUpper(&a, &b, &c);

    printf("%s\n", str);

    printf("Caracterele transformate sunt %c, %c, %c\n", a, b, c);

    return 0;
}