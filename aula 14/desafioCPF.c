/*
Augusto César Graeml
*/
#include <stdio.h>
#define N 11

int ehValido(int *cpf);

int main()
{

    int valido, cpf[N] = {1,0,0,2,8,0,1,6,9,4,0};

    valido = ehValido(cpf);

    if(valido)
        printf("Eh valido");
    else
        printf("Nah eh valido");

    return 0;
}

int ehValido(int *cpf)
{
int controle_1, controle_2, num, i, controle_2_certo = 0, controle_1_certo = 0;

    for(i = 0; i < 9; i++)
    {
        num += (i+1) * cpf[i];
    }

    controle_1 = (num%11)%10;

    num = 0;

    for(i = 1; i < 10; i++)
    {
        num += i * cpf[i];
    }

    controle_2 = (num%11)%10;

    if (controle_1 == cpf[9])
        controle_1_certo = 1;

    if (controle_2 == cpf[10])
        controle_2_certo = 1;

    if(controle_1_certo && controle_2_certo)
        return 1;
    else
        return 0;
}
