#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MIN 25
#define MAX 85

int main()
{
int media, valores [N], soma, i,j = 0,k = 0;

soma = 0;

    for (i = 0 ; i < N ; i++)
    {
        valores[i] = MIN + rand() % (MAX - MIN + 1);

        soma += valores[i];
    }

    media = soma / N;

    for (i = 0; i < N ; i++)
    {
        if (valores[i] < media )
        {
            printf("%d eh menor que a media\n", valores[i]);
            j++;
        }

        else if ( valores[i] > media)
        {
            printf("%d eh maior que a media\n", valores[i]);
            k++;
        }

    }

    printf("%d foram maiores que a media e %d foram menores que a media\n", j, k);




return 0;
}
