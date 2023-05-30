
#include <stdio.h>
int main()
{
/**passagem de passagem de vetores por parametros de função*/

int cima = 1, direita = 2, baixo = 3, esquerda = 4;

for(i=0; i<; i++)
    for(j=0; j< ; j++)
    {
        if(matriz[i][j] == -1)
            if(matriz[i-1][j] == -1)//cima
                return 1;
            if(matriz[i+1][j] != -1)//baixo
                return 3;
            if(matriz[i][j+1] != -1)//direita
                return 2;
            if(matriz[i][j-1] != -1)
                esquerda = 0;
    }


esquerda
baixo
cima





return 0;
}
