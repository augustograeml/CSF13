#include <stdio.h>
#define N 4

void geraMatrizInca (int matriz [N][N]);

int main()
{
int matriz[N][N];

geraMatrizInca(matriz);

return 0;
}
void geraMatrizInca (int matriz [N][N])
{
    int auxiliar = 0, contador, num = 1, i, j;

    //gerar a matriz
    while(contador <= N*N)
    {

        for(contador = auxiliar; contador < N - auxiliar ; contador++)
            matriz[auxiliar][contador] = num++;

        for(contador = auxiliar + 1; contador < N - auxiliar ; contador++)
            matriz[contador][N - auxiliar] = num++;

        for(contador = N - auxiliar -1; contador >= auxiliar; contador--)
            matriz[N - auxiliar][contador] = num++;

        for(contador = N - auxiliar -1; contador >= auxiliar + 1; contador--)
            matriz[contador][auxiliar] = num++;

        auxiliar++;
    }
    //imprimir a matriz
    for(i=0; i < N; i++)
    {
        for(j=0; j < N; j++)
            printf("%d", matriz[i][j]);

        printf("\n");
    }
}
