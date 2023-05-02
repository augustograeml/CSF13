#include <stdio.h>

#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */

int eh_par (int i);
void pontoRolo1 ();
void pontoRolo2 ();
void moveAgulha ();//
void rolaTecido ();//empurra o tecido e  reposiciona

void main ()
{
int i = 0,j,k, l = 0;
/* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        l++;

        if (eh_par(l))
        {
           for(i = 0; i <= LARGURA_FAIXA ; i++ )
            {
                for(j = 0; j <= LARGURA_FAIXA -i; j++)
                {
                    if (j < 6 - i)
                        moveAgulha();
                    else
                        for(k = 0; k < 6 - j; k++)
                            pontoRolo2();
                }
                rolaTecido();
            }
        }
        else
        {
            for(i = 0; i <= LARGURA_FAIXA ; i++ )
            {
                for(j = 0; j <= LARGURA_FAIXA -i; j++)
                {
                    if (j < 6 - i)
                        moveAgulha();
                    else
                        for(k = 0; k < 6 - j; k++)
                            pontoRolo1();
                }
                rolaTecido();
            }
        }


    }
}
int eh_par(int i)
{
    if(i%2 == 0)
        return(1);
    else
        return(0);
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
