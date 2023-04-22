#include <stdio.h>

int main()
{
int ano_atual, ano_nascimento,
    ano_INSS, idade,
    contribuicao;

    printf("Digite o ano do seu nascimento: ");
    scanf("%d", &ano_nascimento);

    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    printf("Digite o ano de inicio da sua contribuição para o INSS: ");
    scanf("%d", &ano_INSS);

    idade = ano_atual - ano_nascimento;
    contribuicao = ano_atual - ano_INSS;

    if (idade >= 60)
    {
        if ((contribuicao >= 25) || (idade > 65))
        {
                printf("Sua idade é %d e você pode se aposentar", idade);
        }
        else
        {
                printf("Sua idade é %d e você não pode se aposentar)");
        }
    }
    else if (contribuicao >= 30)
     {
         printf("Sua idade é %d e você pode se aposentar", idade);
     }
    else
    {
        printf("Você não pode se aposentar!");
    }



return 0;
}
