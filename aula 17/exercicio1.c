/*-------------------------------
EXERCÍCIO 1 - Aula 17 - 23/05/2023
MINHOCAS (matriz, recolhe o maior elemento de cada linha e no final soma)
-------------------------------*/

#include <stdio.h>
#define N_LINHAS 3
#define N_COLUNAS 4

int main()
{
    int campo [N_LINHAS][N_COLUNAS] = {{100},
                                      {110},
                                      {0},
                                      {100}};

    int i, j, maior_soma = 0, soma = 0;


    for(i = 0; i < N_LINHAS; i ++)
    {
        for(j = 0; j < N_COLUNAS; j++)
        {
           soma += campo[i][j];
        }

        if(soma > maior_soma)
            maior_soma = soma;

        soma = 0;
    }

    for(j = 0; j < N_COLUNAS; j ++)
    {
        for(i = 0; i < N_LINHAS; i++)
        {
           soma += campo[i][j];
        }


        if(soma > maior_soma)
            maior_soma = soma;

        soma = 0;
    }
    printf("%d", maior_soma);




return 0;
}
