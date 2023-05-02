#include <stdio.h>

int ehBissexto (int ano);

int main()
{
int ano,  resultado;

    printf("Digite um ano: ");
    scanf("%d", &ano);

    resultado = ehBissexto(ano);

    printf("%d", resultado);




return  0;
}
int ehBissexto (int ano)
{
    if(ano%400 == 0)
        return 1;
    else if (ano%4 == 0 && ano%100 != 0)
        return 1;
    else
        return 0;


}
