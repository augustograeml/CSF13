#include <stdio.h>
int main()
{
//declarar variáveis de controle de iteração  i, j
int i, j, k;
//começar um loop para rodar de 1 até 6 para o primeiro dado
    for(i = 1; i < 7; i++)
    {
    //começar um loop aninhado para contar de 1 até 6 repŕesentado os resultados do segundo dado
        for(j = 1; j < 7; j++)
        {
            //printar o i seguido do j
            for(k = 1; k < 7; k++)
            {
                printf("%d \t %d \t %d\n", i, j, k);
            }

        }


    }
return 0;
}
