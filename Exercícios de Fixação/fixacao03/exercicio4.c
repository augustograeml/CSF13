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
         printf("A sua idade � %d, e voc� � eleitor  facultativo! " ,idade);
    }
    else if (idade >= 65)
    {
         printf("A sua idade � %d, e voc� � eleitor  facultativo! " ,idade);
    }
    else
    {
        printf("A sua idade � %d, e voc� � eleitor obrigat�rio!", idade);
    }

}
else
{
     printf("A sua idade � %d, e voc� n�o � eleitor! " ,idade);

}



return  0;
}
