/*----------------------------
Exercicio 1 - Aula 20 - 06/06/2023
Maior Medio Menor
----------------------------*/
#include <stdio.h>

typedef struct {

    float maior;
    float medio;
    float menor;

} MaMeMe;

void troca (float *a, float *b);

MaMeMe classifica (float n1, float n2, float n3);

int main()
{
    float n1 = 6.5, n2 = 7.0 ,n3 = 10.1;

     MaMeMe num = classifica(n1,n2,n3);

     printf("%f\n %f\n %f\n", num.maior, num.medio, num.menor);

return 0;
}
void troca (float *a, float *b)
{
    float aux = *a;
    *a = *b;
    *b = aux;

}

MaMeMe classifica (float n1, float n2, float n3)
{
    MaMeMe num;

    num.menor = n1;
    num.medio = n2;
    num.maior = n3;

    if(num.medio > num.maior)
        troca(&num.medio, &num.maior);
    if(num.menor > num.medio)
    {
        troca(&num.menor, &num.medio);

        if(num.medio > num.maior)
            troca(&num.medio, &num.maior);
    }


    return (num);
}
