/*------------------------------------
Exercício 3 - Aula 17 - 29/05/2023
Matriz aleatória para matriz Transposta!
-------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 3
int main()
{
    int matrizA[L][C], matrizT[C][L];
    int i, j;

    printf("MATRIZ A: \n");

    for(i = 0; i < L; i++)
    {
        for(j = 0; j < C; j++)
        {
            matrizA[i][j] = rand()%21;
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }

     printf("MATRIZ TRANSPOSTA: \n");

    for(j = 0; j < L; j++)
    {
        for(i = 0; i < C; i++)
        {
            matrizT[j][i] = matrizA[i][j];
            printf("%d ", matrizT[j][i]);
        }
        printf("\n");
    }



return 0;
}
