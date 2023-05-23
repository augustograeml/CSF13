/*----------------------------------
Exercício 2 - Aula 16 - 23/05/2023
Vetor recebe o valor dos dois outros multiplicados
NÃO FUNCIONA!!!!
----------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

int multiplicaOsDois (int* v1, int* v2);

int main()
{
int i, tam1, tam2;
int* v1;
int* v2;
int* v3;

    scanf("%d", &tam1);
    scanf("%d", &tam2);

    v1 = (int*) malloc (tam1 * sizeof (int));
    v2 = (int*) malloc (tam2 * sizeof (int));

    if(tam1 > tam2)
        for(i = 0; i < tam1; i++)
        {
            v1[i] = rand()%11;
            v2[i] = rand()%11;
        }
    else
        for(i = 0; i <tam2; i++)
        {
           v1[i] = rand()%11;
           v2[i] = rand()%11;
        }

    v3 = multiplicaOsDois(v1, v2);

    for(i = 0; i < N; i++)
    {
        printf("%d", v3[i]);
    }

    free(v1);
    free(v2);3




return 0;
}

int multiplicaOsDois (int* v1, int* v2)
{
    int i;
    int* resultado;

    for(i = 0; i < N; i++)
    {
        resultado[i] = v1[i] * v2[i];
    }

    return (resultado);

}
