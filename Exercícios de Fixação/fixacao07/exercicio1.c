#include <stdio.h>
int main()
{
int num;

printf("Insira um número inteiro: ");
scanf("%d", &num);

    while (num < 20 && num > 10)
    {
        printf("Eco %d\n", num);

        printf("Insira um número inteiro: ");
        scanf("%d", &num);

    }


return 0;
}
