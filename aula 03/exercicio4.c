#include <stdio.h>
int main()
{
int hora_inicial, hora_final,
    duracao;

    printf("Digite a hora inicial da partida: ");
    scanf("%d", &hora_inicial);

    printf("Digite a hora final da partida: ");
    scanf("%d", &hora_final);

    duracao = hora_final - hora_inicial;

    if(hora_final < hora_inicial )
    {
        duracao = duracao + 24;
        printf("A partida durou: %dh.", duracao);
    }
    else
    {

        if (duracao >= 1)
        {
            if(duracao <= 24)
            {
                printf("A partida durou: %dh.", duracao);
            }
            else
            {
                printf("Duração inválida!");
            }
        }
        else if (duracao == 0)
        {
            duracao = 24;
            printf("A partida durou %dh.", duracao);
        }
        else
        {
            printf("Duração inválida!");
        }

    }








return 0;
}
