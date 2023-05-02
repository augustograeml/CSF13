#include <stdio.h>
int main()
{
    //1 1 1
    //1 1 2
    //1 1 3
    //1 2 1
    //1 2 2
    //1 2 3
    //1 3 1
    //1 3 2
    //1 3 3
    //-2 1 1
    //2 1 2
    //2 1 3
    //-2 2 1
    //2 2 2
    //2 2 3
    //-2 3 1
    //2 3 2
    //2 3 3
    //-3 1 1
    //-3 1 2
    //3 1 3
    //-3 2 1
    //-3 2 2
    //3 2 3
    //-3 3 1
    //-3 3 2
    //3 3 3

//declarar variáveis de controle de iteração  i, j
int i, j, k;
//começar um loop para rodar de 1 até 6 para o primeiro dado
    for(i = 1; i < 4; i++)
    {
    //começar um loop aninhado para contar de 1 até 6 repŕesentado os resultados do segundo dado
        for(j = i; j < 4; j++)
        {
            //printar o i seguido do j
            for(k = j; k < 4; k++)
            {
                printf("%d \t %d \t %d\n", i, j, k);
            }

        }


    }
return 0;
}
