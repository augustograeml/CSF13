/*------------------------------------
Exercício 1 - Aula 17 - 29/05/2023
Gera uma matriz com os produtos de i*j e imprime
-------------------------------------*/
#include <stdio.h>

#define N_LINHAS 7
#define N_COLUNAS 5
int main ()
{
int i, j;
int matriz_foo [N_LINHAS][N_COLUNAS];
    for (i = 0; i < N_LINHAS; i++)
    {
        for (j = 0; j < N_COLUNAS; j++)
        {
            matriz_foo [i][j] = i*j;
            printf("%d ", matriz_foo[i][j]);
        }
        printf("\n");
    }

return (0);
}
