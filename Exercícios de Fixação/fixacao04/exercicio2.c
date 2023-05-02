#include<stdio.h>
int main()
{
int numero;

printf("Insira um numero inteiro:");
scanf("%d", &numero);

    if ((numero%2 == 0 &&  numero > 10) || (numero%2 == 1 && numero < 50 ))
    {
        printf("SIM");
    }
    else
    {
        printf("NÃO");
    }


return 0;
}
