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

    printf("Digite o ano de inicio da sua contribui��o para o INSS: ");
    scanf("%d", &ano_INSS);

    idade = ano_atual - ano_nascimento;
    contribuicao = ano_atual - ano_INSS;

    if (idade >= 60)
    {
        if ((contribuicao >= 25) || (idade > 65))
        {
                printf("Sua idade � %d e voc� pode se aposentar", idade);
        }
        else
        {
                printf("Sua idade � %d e voc� n�o pode se aposentar)");
        }
    }
    else if (contribuicao >= 30)
     {
         printf("Sua idade � %d e voc� pode se aposentar", idade);
     }
    else
    {
        printf("Voc� n�o pode se aposentar!");
    }



return 0;
}
