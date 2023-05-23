#include <stdio.h>
#include <string.h>
#define N 1024

char* concatenaStrings (char* s1, char* s2);
char* empacotaString (char* string);


int main()
{
    char s1[1024],s2[1024];
    char* copia, *s1_empacotada, *s2_empacotada;

    fgets(s1, N, stdin);
    s1[strlen(s1)-1] = '\0';
    s1_empacotada = empacotaString(s1);

    fgets(s2, N, stdin);
    s2_empacotada = empacotaString(s2);

    copia = concatenaStrings(s1_empacotada, s2_empacotada);

    printf("%s", copia);

    free(copia);

return 0;
}
char* concatenaStrings (char* s1, char* s2)
{
    int tam1 = strlen(s1);
    int tam2 = strlen(s2);
    int i, k = 0;

    int tamanho_total = tam1 + tam2 + 1;

    char *copia = (char*) malloc (tamanho_total * sizeof (char));

    for(i = 0; i < tam1; i++)
    {
        copia[k] = s1[i];
        k++;
    }
    for(i = 0 ; i < tam2 ; i++)
    {
        copia[k] = s2[i];
        k++;
    }

    return(copia);
}

char* empacotaString (char* string)
{
    char* copia;
    int tam = 0, i;

    for(i = 0; string[i] != '\0'; i++)
        tam++;


    copia = (char*) malloc ((tam + 1) * sizeof (char));

    for(i = 0; i < tam ; i++)
    {
        copia[i] = string[i];
    }
    copia[tam] = '\0';

    return(copia);
}

