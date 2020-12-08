#include <stdio.h>
#include <stdbool.h>

bool estePerfect(int a)
{
    int s = 0;

    for(int i = 1; i <= a / 2; i++)
    {
        if(a % i == 0)
        {
            s += i;
        }
    }

    return a == s;
}


int main()
{
    int n;

    printf("Cititi un numar natural: ");
    scanf("%d", &n);

    if(estePerfect(n))
        printf("Numarul este perfect.\n");
    else
        printf("Numarul nu este perfect.\n");

    return 0;
}