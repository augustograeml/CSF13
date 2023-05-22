/*-------------------------------   
EXERCICIO 3 -- Aula 12 -- 09/05/2023
SEQUENCIA K ALTERNANTE 
(A sequência 1 3 6 8 9 11 2 4 1 7 6 8 é 2-alternante. A sequência 2 1 4 7 8 9 12 é 1-alternante.
 A sequência 4 2 3 1 6 4 2 9 3 não é alternante. A sequência 1 3 5 é 3-alternante.)
-------------------------------*/
#include <stdio.h>

int eh_k_alternante(int n, int *k_alternante);

int main()
{
int n;

    scanf("%d", &n);


    if(eh_k_alternante(n))
        printf("A sequencia eh alternante");
    else
        printf("A sequencia nao eh alternante");



return 0;
}

int eh_k_alternante(int n, int *k_alternante)
{
    int i, j = 0, k = 0, eh_impar = 0, eh_par = 0, num;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if(num%2 != 0)
            eh_impar = 1;
        else
            eh_par = 1;

        if(eh_impar)
            j++;

        if(eh_par)
            k++;

        if(j == k)
            return 1;
        else
            return 0;
    }


}
