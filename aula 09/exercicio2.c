#include <stdio.h>
#define N 5
int main()
{
//variaveis = i,j, soma, num -> i e div para contagem de iterações dos loops -> soma pra calcular a soma dos N primerios numeros -> num para armazenar os números primos -> eh_primo flag para definir se é primo ou não
int i, div, soma, num, eh_primo;

    printf("1\n");
    //loop para rodar enquanto os primeiros N números não forem achados
    num = 3;
    i = 0;
    soma = 1;

    while(i < N )
        {

                eh_primo = 1;
                for(div = 1; div < num; div++)
                {
                    if (num%div == 0 )
                        eh_primo = 0;
                    if(eh_primo)
                    {
                        printf("%d\n",num);
                        soma+=num;
                        i++;
                    }
                    else
                    {
                    }

                }

             num++;
        }
        printf("A soma dos N primeiros números primos é %d", soma);

return 0;
}
