#include <stdio.h>

int main()
{
int  aux, num, algarismo, tem_no_numero;

    printf("Escreva um número inteiro:");
    scanf("%d", &num);
    aux = num;

    printf("Escreva um digito:");
    scanf("%d", &algarismo);


    tem_no_numero = 0;
    while(num > 0)
    {
        if(num%10 == algarismo)
        {
            tem_no_numero = 1;
        }
        num /= 10;

    }
    if(tem_no_numero)
        printf("O algarismo %d se encontra no número %d", algarismo,aux);

    else
        printf("O algarismo %d nao se encontra no numero %d:", algarismo,aux );





return 0;
}
