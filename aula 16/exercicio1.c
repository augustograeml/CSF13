#include <stdio.h>
#include <stdlib.h>


#define N 1024

char* empacotaString (char* string);


int main()
{
int i;
char string[N];
char* vetor;

    fgets (string, N, stdin);

    vetor = empacotaString(string);

    printf("%s", vetor);

    free(vetor);

return 0;
}

char* empacotaString (char* string)
{
    char* copia;
    int tam = 0, i;

    for(i = 0; string[i] != '\0'; i++)
        tam++;


    copia = (char*) malloc ((tam + 1) * sizeof (char));

    for(i = 0; i < tam + 1 ; i++)
    {
        copia[i] = string[i];
    }

    return(copia);
}
