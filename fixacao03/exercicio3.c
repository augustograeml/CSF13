#include <stdio.h>
#include <math.h>

int main()
{
int valor;
int absoluto;
printf("Digite um valor real: ");
scanf("%d", &valor);

if (valor >= 0.0)
{
 printf("O valor absoluto eh %d", valor);
}
else{
absoluto = valor*-1;
printf("O valor absoluto eh %d", absoluto);
}

return 0;
 }
