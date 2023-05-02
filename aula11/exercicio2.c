#include <stdio.h>

#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */

void pontoRolo1 ();
void pontoRolo2 ();
void moveAgulha ();//
void rolaTecido ();//empurra o tecido e  reposiciona

void main ()
{
int i,j,k;
/* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for(i = 0; i <= LARGURA_FAIXA ; i++ )
        {
            for(j = 0; j <= LARGURA_FAIXA -i; j++)
            {
                if (j < 6 - i)
                    pontoRolo1();
                else
                    for(k = 0; k < 6 - j; k++)
                        pontoRolo2();
            }
            rolaTecido();
        }
    }
}
void pontoRolo1 ()
{
    printf("V ");
}
void pontoRolo2 ()
{
    printf("A ");
}
void moveAgulha ()
{
    printf(" ");
}
void rolaTecido ()
{
    printf("\n");
}
