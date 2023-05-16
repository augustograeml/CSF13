#include <stdio.h>
int main()
{
int n1, n2,
    n3, maior;

    printf("Insira um número: ");
    scanf("%d", &n1);

    printf("Insira outro número: ");
    scanf("%d", &n2);

    printf("Insira mais um número: ");
    scanf("%d", &n3);

    if (n1 > n2)
    {
        if (n1 > n3)
        {
        maior = n1;
        }
        else
        {
        maior = n3;
        }
    }
    else
    {
        if(n2 > n3)
        {
        maior = n2;
        }
        else
        {
        maior = n3;
        }
    }

printf("O maior número é: %d\a", maior);

return 0;
}
