#include <stdio.h>
int main()
{

int min , max, aux, maiorValor, menorValor, i, eh_positivo;
maiorValor = 0;
menorValor = 10;
i = 0;
eh_positivo = 1;

    printf("Insira o valor máximo da faixa: ");
    scanf("%d" , &max);

    printf("Insira um valor mínimo da faixa: ");
    scanf("%d" , &min);

    printf("Insira um valor inteiro: ");
    scanf("%d" , &aux);

    if(aux < max && aux > min)
    {

        eh_positivo = 1;
        while (eh_positivo)
        {
            if(aux > 0)
            {
                if (aux > maiorValor)
                    maiorValor = aux;
                if (aux < menorValor)
                    menorValor = aux;

                i++;


                printf("Insira um valor inteiro: ");
                scanf("%d" , &aux);
            }
            else
            {
                eh_positivo = 0;
            }
        }

         printf("%d números inseridos e o %d foi o menor número inserido e %d foi o maior numero inserido!", i, menorValor, maiorValor);
    }

    else
    {
         printf("ERRO! Números fora da faixa!");
    }


return 0;
}
