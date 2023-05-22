/*-------------------------------   
EXERCICIO 1 -- Aula 13 -- 11/05/2023
CALCULA A MÉDIA E IMPRIME APENAS OS VALORES POSITIVOS
-------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define N 10
#define MIN -40
#define MAX 40

int main()
{
int i, eh_positivo = 0, soma, qtde_maior = 0, qtde_menor = 0;
float valores[eh_positivo], val, media = 0;

    for(i = 0; i < N ; i++)
    {
        val = (rand()/(float)RAND_MAX) * (MAX - MIN) + MIN;

        if(val > 0 )
        {
            valores[eh_positivo] = val;
            soma += valores[eh_positivo];
            eh_positivo++;
        }

    }

    media = soma/eh_positivo;

    for (i = 0 ; i < eh_positivo ; i++)
    {
        if (valores[i] > media)
        {
            printf("%f eh maior que a media\n", valores[i]);
            qtde_maior++;
        }
        else
        {
            printf("%f eh menor que a media\n", valores[i]);
            qtde_menor++;
        }

    }
    printf("A media foi %f \t %d foram maiores que a media \t %d foram menores que a media ", media, qtde_maior, qtde_menor);


return 0;
}
