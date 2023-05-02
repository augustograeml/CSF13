#include <stdio.h>
int main()
{
int ano_atual;
int ano_nascimento;
int idade;

printf("Digite o ano do seu nascimento:");
scanf("%d", &ano_nascimento);

printf("Digite o ano atual:");
scanf("%d", &ano_atual);

idade  = (ano_atual - ano_nascimento);

if  (idade >=  16)
{
    if  (idade < 18)
    {
         printf("A sua idade é %d, e você é eleitor  facultativo! " ,idade);
    }
    else if (idade >= 65)
    {
         printf("A sua idade é %d, e você é eleitor  facultativo! " ,idade);
    }
    else
    {
        printf("A sua idade é %d, e você é eleitor obrigatório!", idade);
    }

}
else
{
     printf("A sua idade é %d, e você não é eleitor! " ,idade);

}



return  0;
}
