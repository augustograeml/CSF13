#include <stdio.h>
int main()
{
//receber um número n e armazenar em uma variável do tipo char
int n, i, j;
char car = 0;

        scanf("%d", &n);
//começar um loop que começa em i = n e decrementa a cada iteração
    for(i = 0 ; i < n; i++)
    {
        for(j = 0; j < n-i; j++)
        {
            car = 'A' + n - i;
            printf("%c\t", car -1);
        }
        printf("\n");

    }
    //dentro começar outro loop que printa o caracter \t e decrementa o a variavel caracter




return 0;
}
