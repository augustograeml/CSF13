#include <stdio.h>
int main()
{
int numeroA,
    centena,
    dezena,
    unidade,
    numeroI;

    printf("Insira um número entre 100 e 999: ");
    scanf("%d", &numeroA);

    centena = numeroA/100;
    dezena = (numeroA%100)/10;
    unidade = (numeroA%100)%10;

    printf("O seu número é: %d%d%d", unidade, dezena, centena);





return 0;
}
