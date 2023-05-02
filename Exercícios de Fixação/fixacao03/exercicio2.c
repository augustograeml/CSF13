#include <stdio.h>
#include <math.h>

int main()
{
int valor;
float raiz;
printf("Digite um valor Real: ");
scanf("%d", &valor);

if (valor >= 0.0)
{
 raiz = sqrt(valor);
 printf("A raiz quadrada é %f.", raiz);
}
else{
 printf("Não foi possível calcular a raiz.");
}

return 0;
 }
