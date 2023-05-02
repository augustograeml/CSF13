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
