/*-------------------------------
EXERCÍCIO 4 - Aula 17 - 23/05/2023

-------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

int main()
{
int i, j, k, matrizA[N][M], matrizB[M][N], matrizC[N][N];
 //gerar as matrizes e printa
 printf("MATRIZ A \n");
 for(i = 0; i < N; i++)
 {
    for(j = 0; j < M; j++)
    {
        matrizA[i][j] = rand()%11;

        printf("%d ", matrizA[i][j]);
    }
    printf("\n");
 }

    printf("\n");
    printf("MATRIZ B \n");
 for(i = 0; i < M; i++)
 {
    for(j = 0; j < N; j++)
    {
        matrizB[i][j] = rand()%11;

        printf("%d ", matrizB[i][j]);
    }
    printf("\n");
 }
 //calculo da multiplicação

    printf("MATRIZ C \n");
 for(i = 0; i < N; i++)
 {
    for(j = 0; j < N; j++)
    {
        matrizC[i][j] = 0;

        for(k=0; k < N; k++)
        {
        matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
        }
        printf("%d ", matrizC[i][j]);
    }
    printf("\n");
 }


return 0;
}
