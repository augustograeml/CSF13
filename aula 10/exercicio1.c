#include <stdio.h>

int arredonda (double x);

int main ()
{
double x;
float resultado;

    scanf("%lf",&x);

    resultado = arredonda(x);

    printf("%.f", resultado);


return 0;
}

int arredonda (double x)
{
    int resultado, aux;

    if(x < 0)
    {
        x -= 0.5;

        return (int)x;
    }
    else
    {
        x += 0.5;

        return (int)x;
    }

}
