#include <stdio.h>
#include <stdbool.h>

bool estePalindrom(int a)
{
    int inv = 0, cop = a;

    while (a)
    {
        inv = inv * 10 + a % 10;
        a /= 10;
    }
    
    return inv == cop;
}

int main()
{
    int n;

    printf("Cititi un numar natural: ");
    scanf("%d", &n);

    if(estePalindrom(n))
        printf("Numarul este palindrom.\n");
    else
        printf("Numarul nu este palindrom.\n");

    
    return 0;
}