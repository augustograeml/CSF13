#include <stdio.h>

int proxFibonacci (int n);

int main ()
{
    int n, proximo;
    scanf("%d", &n);

    proximo = proxFibonacci(n);

    printf("%d" , proximo);


return 0;
}

int proxFibonacci (int n)
{
    int valor_atual, valor_anterior, aux, i;

    valor_anterior = 0;
    valor_atual = 1;



    for(i = 0; i < n && valor_atual < n; i++)
    {
        aux = valor_atual;
        valor_atual += valor_anterior;
        valor_anterior = aux;
    }

    return valor_atual;
}
