#include <stdio.h>

int main()
{
int num, divisor, dividendo, quociente = 0, resto, i, aux;

    printf("Escreva dois números inteiros:");
    scanf("%d/%d", &dividendo, &divisor);

    aux = dividendo;

    for (i = 0; i <= divisor; i++)
    {
        dividendo -= divisor;
        quociente++;

    }
    resto = dividendo;
        printf("dividendo: %d \n divisor: %d \n quociente: %d \n resto: %d",aux,divisor,quociente, resto);





return 0;
}
