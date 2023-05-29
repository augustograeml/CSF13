/*------------------------------------
Exercício 2 - Aula 18 - 29/05/2023
-------------------------------------*/
#include <stdio.h>
#define N_LINHAS 3
#define N_COLUNAS 3

int temRepetição (int matriz[N][M]);

int main ()
{
    int i, j;
    int matriz [N_LINHAS][N_COLUNAS];
    srand (time (NULL));
    /* Preenche */
    for (i = 0; i < N_LINHAS; i++)
        for (j = 0; j < N_COLUNAS; j++)
            matriz [i][j] = rand () % 100;
    /* Imprime */
    for (i = 0; i < N_LINHAS; i++)
    {
        for (j = 0; j < N_COLUNAS; j++)
            printf ("%d\t", matriz [i][j]);
        printf ("\n");
    }
    /* Testa */
    if (temRepeticao (matriz))
        printf ("Tem elementos repetidos.");
    else
        printf ("Nao tem elementos repetidos.");
    return (0);
}

int temRepetição (int matriz[N][M])
{
    int i, j, k,tem_repetição;

    int auxilia = malloc (N*M * sizeof(int));

    for(i=0; i < N; i++)
    {
        for(j=0; j < M; j++)
        {
            for(k = 0; k < N*M; k++)
            {
                auxilia[k] = matriz[i][j];
            }
        }

    }
    for(i=0; i < N; i++)
    {
        for(j=0; j < M; j++)
        {
            for(k = 0; k < N*M; k++)
            {
                if(auxilia[k] == matriz[i][j])
                {
                    return 1;
                }
            }
        }
    }

}
