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
 printf("A raiz quadrada � %f.", raiz);
}
else{
 printf("N�o foi poss�vel calcular a raiz.");
}

return 0;
 }
