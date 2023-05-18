#include <stdio.h>
#include <stdlib.h>
#define N 11234
int numPalavras(char *string);
int ehLetra (char c);

int main()
{
int num_palavras;
char frase[N];
scanf("%s", frase);

num_palavras = numPalavras(frase);

printf("%d", num_palavras);



return 0;
}

int ehLetra (char c)
{
     if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;

}

int numPalavras(char *string)
{
    int n = 0, palavras = 0, i;

    while(string[n] != '\0')
        n++;

    for(i = 0; i < n; i++)
    {
        if(ehLetra(string[i]) && !ehLetra(string[i+1]))
        palavras++;
    }
    return palavras;

}
