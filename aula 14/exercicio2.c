/*-------------------------------   
EXERCICIO 22 -- Aula 14 -- 16/05/2023
RETIRA UM NÚMERO DO VETOR E DESLOCA TODOS PARA A ESQUERDA
--------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
int aleatorio[N], num, i, tam = N;

    for(i = 0; i < N ; i++)
    {
        aleatorio[i] = rand()%11;
        printf("%d\t", aleatorio[i]);

    }
    printf("\n");
    printf("Insira o número a ser retirado");
    scanf("%d", &num);
    i = 0;
    while(tam > 0 && num < tam)
    {
        for(i = num; i < tam - 1; i++)
        {
            aleatorio[i] = aleatorio[i+1];
            printf("%d ", aleatorio[i]);
        }
        scanf("%d", &num);
        tam--;
    }


return 0;
}
