#include <stdio.h>
int main()
{
int num_original, num, eh_palindromo = 1, primeiro, ultimo;

scanf("%d", &num);
num_original = num;

    while (num && eh_palindromo)
    {
        removeExtremos (&num, &primeiro, &ultimo);

        if(primeiro != ultimo)
            eh_palindromo = 0;

    }

    if(eh_palindromo)
        printf("O numero %d eh palindromo", num_original);
    else
        printf("O numero %d nao eh palindromo", num_original);




return 0;
}

void removeExtremos (int *n, int *pri, int *ult)
{
    int tn, pot = 1;

    tn = *n;

    while(tn >= 10)
    {
        tn = tn/10;
        pot *= 10;
    }

    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}
