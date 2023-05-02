#include <stdio.h>


int main()
{
int velocidade_maxima, velocidade_motorista,
    multa;

    printf("Informe a velocidade máxima da via: ");
    scanf("%d", &velocidade_maxima);

    printf("Informe a velocidade do motorista:  ");
    scanf("%d", & velocidade_motorista);

    multa = (velocidade_motorista - velocidade_maxima)*50;

    if (multa > 0)
    {
        printf("A velocidade limite foi excedida! A sua multa é de R$ %d", multa);
    }
    else
    {
        printf("O limite de velocidade não foi excedido, portanto não há multa.");
    }


return 0;
 }
