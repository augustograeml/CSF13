#include <stdio.h>

int main()
{

int i, num, fatorial;

    printf("Digite um número:");
    scanf("%d", &num);

    fatorial = 1;
    for(i = num; i > 1 ; i--)
    {
        fatorial *= i;
    }

    printf("O número %d tem fatorial igual a: %d", num, fatorial);



return 0;
}
