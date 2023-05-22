/*-------------------------------   
EXERCICIO 3 -- Aula 14 -- 16/05/2023
STRING DO CEBOLINHA (TROCA R POR L)
---------------------------*/

#include <stdio.h>
#include <string.h>
#define MAX 50


void stling (char *s, char *buffer);
int main()
{
int i, tam;
char s[MAX], copia_s[MAX];

scanf("%s", s);

tam = strlen(s);

stling(s, copia_s);

printf("%s", copia_s);


return 0;
}

void stling (char *s, char *buffer)
{
    int  i, tam;

    tam = strlen(s);

    for(i = 0; i < tam ; i++ )
    {
        if(i != 0 && i != tam - 1)
        {

            if (s[i] == 'R' || (s[i] == 'R' && s[i] == s[i+1]))
                buffer[i] = 'L';
            else if (s[i] == 'r' || (s[i] == 'r' && s[i] == s[i+1]))
                buffer[i] == 'l';
            else
                buffer[i] = s[i];
        }
        else
            buffer[i] = s[i];
    }
}
