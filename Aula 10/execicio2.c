#include <stdio.h>

double casasDecimais (double  x);

int main ()
{
    double x;
    float resultado;


    scanf("%lf", &x);

    resultado = casasDecimais(x);

    printf("%f", resultado);



return 0;
}

    double casasDecimais (double  x)
    {
        if(x < 0)
            return x + (int)x;
        else
            return x - (int)x;


    }
