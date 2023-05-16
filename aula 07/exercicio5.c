#include <stdio.h>

int main()
{
int i, j, num, num_anterior, eh_crescente, eh_decrescente;

    printf("Digite um número:");
    scanf("%d", &num);
    i = 0;
    j = 0;
    while(num > 0 )
    {
        printf("Digite um número:");
        scanf("%d", &num);

        if(num <= num_anterior)
        {
            eh_decrescente = 1;
            i++;
        }
        else

        if(num >= num_anterior)
        {
            eh_crescente = 1;
            j++;
        }

    }
    if(eh_crescente)
        printf("A maior sequência crescente tem tamanho %d",i);
    else
        printf("A maior sequência decrescente tem tamanho %d", j);





return 0;
}
