#include <stdio.h>
unsigned int inverteNum (unsigned int n);
int main ()
{
int n, numInvertido;

    scanf("%d", &n);
    numInvertido = inverteNum(n);

    printf("%d", numInvertido);




return 0;
}

unsigned int inverteNum (unsigned int n)
{
    int resto, invertido;

    while (n != 0)
    {
        resto = n % 10;
        invertido = invertido * 10 + resto;
        n /= 10;
    }

    return invertido;

}
