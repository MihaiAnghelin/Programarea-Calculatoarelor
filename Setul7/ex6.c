#include <stdio.h>
#include <string.h>

int main()
{
    char s[30];

    printf("Introduceti sir: ");
    fgets(s, 30, stdin);

    char* p;

    p = strtok(s, " ");
    while (p)
    {
        printf("%s\n", p);

        p = strtok(NULL, " ");
    }
    

    printf("Sirul este: %s\n", s);
}