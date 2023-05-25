#include <stdio.h>
#include "trabalho2.h"

void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i;

    for(i = 0; i < n_amostras; i++ )
    {
        dados[i] = dados[i]*ganho;
    }

}
void misturaDados (double* dados1, double* dados2, double* saida, int n_amostras)
{
    int i;

    for(i =0; i < n_amostras; i++)
    {
        saida[i] = dados1[i] + dados2[i];
    }

}
void inverteSinal (double* dados, int n_amostras)
{
    int i;
    double aux;

    for(i = 0; i < n_amostras/2; i++)
    {
        aux = dados[n_amostras - i - 1];
        dados[n_amostras - i] = dados[i];
        dados[i] = aux;
    }

}
void atrasaSinal (double* dados, int n_amostras, int atraso)
{
    int i, aux;

    if(atraso > 0)
    {
        for(i = 0; i < atraso; i++)
        {
            aux = dados[i];
            dados[i + 1] = aux;
            dados[i] = 0;
        }
    }
    else if(atraso < 0)
    {
        for(i = n_amostras; i > n_amostras + atraso; i--)
        {
            aux = dados[i];
            dados[i-1] = aux;
            dados[i] = 0;
        }

    }
}
