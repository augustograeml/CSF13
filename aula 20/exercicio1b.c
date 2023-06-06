/*----------------------------
Exercicio 1 b - Aula 20 - 06/06/2023
Maior Medio Menor
----------------------------*/
#include <stdio.h>

typedef struct {

    float maior;
    float medio;
    float menor;

} MaMeMe;

void troca (float *a, float *b);

void classifica (MaMeMe *valores);

int main()
{
    MaMeMe valores;

    valores.menor = 2.0;
    valores.medio = 3.0;
    valores.maior = 1.0;


     classifica(&valores);

     printf(" %f\n %f\n %f\n", valores.maior, valores.medio, valores.menor);

return 0;
}
void troca (float *a, float *b)
{
    float aux = *a;
    *a = *b;
    *b = aux;

}

void classifica (MaMeMe* valores)
{

    if(valores->medio > valores->maior)
        troca(&valores->medio, &valores->maior);

    if(valores->menor > valores->medio)
    {
        troca(&valores->menor, &valores->medio);

        if(valores->medio > valores->maior)
            troca(&valores->medio, &valores->maior);
    }

}
