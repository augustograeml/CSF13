#include <stdio.h>

int main()
{
int num_atual, aux, i, n, num_anterior, eh_crescente, eh_decrescente;

    printf("Escreva a quantidade de números que quer inserir: ");
    scanf("%d", &n);

    printf("Insira um número:");
    scanf("%d", &num_anterior);

    eh_crescente = 1;
    eh_decrescente = 1;
    for(i = 1; i < n; i++)
    {
        printf("Insira um número:");
        scanf("%d", &num_atual);
        if(num_atual >= num_anterior)
            eh_decrescente = 0;
        else
            eh_crescente = 0;

//        printf("%d %d\n", num_anterior, num_atual);

        num_anterior = num_atual;



    }

    if(eh_crescente)
        printf("é crescente");
    else if(eh_decrescente)
        printf("É descrescente");
    else
        printf("Nem um nem outro");

return 0;
}
