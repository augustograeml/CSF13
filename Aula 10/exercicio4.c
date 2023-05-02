#include <stdio.h>
unsigned long long potencia (unsigned int base , unsigned int expoente);

int main ()
{
    unsigned int base, expoente;
    unsigned long long resultado;

    scanf("%d", &base);
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("%d", resultado);

return 0;
}

    unsigned long long potencia (unsigned int base , unsigned int expoente)
    {
        int i, resultado = 1;

        for (i = 0; i < expoente; i++)
        {
            resultado *= base;

        }

        return resultado;
    }
