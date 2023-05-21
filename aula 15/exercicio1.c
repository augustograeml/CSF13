/*----------------------------------------------------------------
EXERCÍCIO 1 - AULA 15 - 18/05/2023 
SAPOS NA LAGOA
-----------------------------------------------------------------*/


#include <stdio.h>
#define N_MAX 100
#define M_MAX 100

int main()
{
int n_pedras, n_sapos, i,j = 0,k, possiveis_posicoes[N_MAX], posicao_inicial, distancia_pulo, posicao = 0;

    scanf("%d", &n_pedras);

    scanf("%d", &n_sapos);

    printf("%d %d", n_pedras, n_sapos);

    for ( i = 0; i < n_sapos; i= i+1)
    {
        printf("%d", i);

        scanf("%d", &posicao_inicial );
        scanf("%d", &distancia_pulo);

        while(posicao < n_pedras)
            {
                posicao = posicao_inicial + distancia_pulo * j;
                possiveis_posicoes[posicao] = 1;
                j++;
            }

            j = 0;
            posicao = posicao_inicial;

        while(posicao >= 0)
            {
            posicao = posicao_inicial - distancia_pulo * j;
            possiveis_posicoes[posicao] = 1;
            j++;
            }

            j = 0;


/* possiveis_posicoes[i] = posicao_inicial - distanci_pulo * i  --> em um loop que vai até posicao ser > 0*/
        /* possiveis_posicoes[i] = posicao_inicial + distanci_pulo * i */
    }

    for(k = 0; k < n_pedras; k++)
        {
            if(possiveis_posicoes[k] != 1)
                possiveis_posicoes[k] = 0;
            printf("%d", possiveis_posicoes[k]);
        }





return 0;
}
