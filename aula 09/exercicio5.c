#include <stdio.h>
int main()
{
//receber o caracter e um numero especificado pelo usuario
int n = 0, i = 0, j, max, num_espaco;
char car1, car2 = ' ';


    printf("Escolha um caracter: \n");
    scanf("%c", &car1);

    printf("Escolha um numero: \n");
    scanf("%d", &n);

    max = 2*n +1;

//loop que incrementa uma variavel i+=2 toda iteração
    while(i < max)
    {
        for (j = 0; j < max; j+=2)
        {
            printf("%c", car1);

        }
         printf("\n");
         printf("%c", car2);
         i+=2;
    }
//e imprime o caracter até i = 2n+1



return 0;
}
