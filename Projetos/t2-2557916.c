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
