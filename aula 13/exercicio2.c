#include <stdio.h>
#include <stdlib.h>

#define N 1024

int main()
{
int n,i;

    //receber o valor de N
    printf("Insira a quantidade de numeros que deseja resgistrar: ");
    scanf("%d", &n );

int valores[N];

    for (i = 0; i < n ; i++ )
    {
        scanf("%d", &valores[i]);

    }
    for(i = n - 1; i >= 0 ; i--)
    {
        printf("\n%d\n", valores[i]);

    }




return 0;
}
