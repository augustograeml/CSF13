#include <stdio.h>
#define N 10

int ehParDeFoolano (unsigned int n1, unsigned int n2);

int main()
{
int n1, n2, aux;

    scanf("%d", &n1);
    scanf("%d", &n2);

    aux = ehParDeFoolano(n1, n2);

    if(aux)
        printf("Os numeros %d e %d formam um par Foolano", n1, n2);
    else
        printf("Os numeros não formam um par Foolano");



return 0;
}

int ehParDeFoolano (unsigned int n1, unsigned int n2)
{
int cont[N], eh_Foolano = 0, i;
    while(n1 > 0)
    {
    // vetor que armazena os contadores de cada numero
      cont[n1%10]++; // posição 0 armazena a quantidade de zeros presentes no n1;
      n1 = n1/10;   //atualiza o n1 retirando o ultimo digito

    }

    while (n2 > 0)
    {
        cont[n2%10]--;
        n2 = n2/10;

    }

    for (i = 0; i < N; i++)
    {
        if(cont[i] != 0)
            eh_Foolano = 1;

    }
    if (eh_Foolano)
        return 1;

    else
        return 0;
}
