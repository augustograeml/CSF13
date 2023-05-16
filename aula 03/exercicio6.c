#include <stdio.h>
int main()
{
    int x, y;

    printf("Insira as coordenadas do ponto: ");
    scanf("%d %d", &x , &y);

    if(x > 0) //se o ponto estiver para o lado positivo do x 1 e 4 quadrante
    {
        if(y > 0)
        {
            printf("O ponto se encontra no Q1");
        }
        else if (y < 0)
        {
            printf("O ponto se encotra no Q4");
        }
        else
        {
            printf("O ponto se encontra em cima do eixo X ");
        }


    }
    else if(x < 0) //se o ponto estiver para o ladp negativo de x 2 e 3 quadrante
    {
        if(y > 0)
        {
            printf("O ponto se encontra no Q2");
        }
        else if (y < 0)
        {
            printf("O ponto se encotra no Q3");
        }
        else
        {
            printf("O ponto se encontra em cima do eixo X  ");
        }


    }
    else
    {
        printf("O ponto se encotra em cima do eixo Y na altura %d", y);
    }


return 0;
}
