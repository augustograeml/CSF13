#include <stdio.h>
int main()
{
 int i, idade;

 i = 0;
 for(i = 0 ; i <= 4 ; i++)
 {
     printf("Digite sua idade: ");
     scanf("%d", &idade);

     printf("Valor digitado: %d \n", idade);

 }



return 0;
}
