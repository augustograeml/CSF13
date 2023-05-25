/*-------------------------------
EXERCÍCIO 2 - Aula 17 - 23/05/2023

-------------------------------*/
#include <stdio.h>
#include <string.h>
#define MAX 128
#define N 3

int main()
{
    int i;
    char vetor_de_strings [N][MAX];

    for(i = 0; i < N; i++)
        fgets(vetor_de_strings[i], MAX, stdin);

    for(i = N - 1; i >= 0; i--)
        printf("%s", vetor_de_strings[i]);



return 0;
}
