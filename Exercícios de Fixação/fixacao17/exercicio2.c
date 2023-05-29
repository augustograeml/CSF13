/*------------------------------------
Exercício 2 - Aula 17 - 29/05/2023
Soma da Linha e da Coluna matriz
-------------------------------------*/
#include <stdio.h>
#define L 2
#define C 4
int main()
{
int matrizA[L][C] = {{0,1,1,0},
                     {1,0,1,1}};

int lin, col, i, j, soma_linha = 0, soma_coluna = 0, soma = 0;

scanf("%d", &lin);
scanf("%d", &col);

for(i = 0; i < lin; i++)
{
    soma_linha += matrizA[lin][i];
    soma_coluna += matrizA[i][col];

}
    soma = soma_linha + soma_coluna;
    soma-= matrizA[lin][col];

  printf("%d", soma);


return 0;
}
