#include <stdio.h>
#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"
#define BUFFER 3000

unsigned int i, j, k, tolerancia = 30;
//unsigned char tolerancia = '0';
char arquivo[BUFFER];
void removeFundo(Imagem3C* img, Imagem3C* bg);

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{


    removeFundo(img, bg);



return 0;
}

void removeFundo(Imagem3C* img, Imagem3C* bg)
{

    for(i=0; i < img->altura; i ++)
    {
        for(j =0; j < img->largura; j++)
        {
            for(k = 0; k < 3; k++)
            {

                if(img->dados[k][i][j] <=( bg->dados[k][i][j] + tolerancia) && img->dados[k][i][j] > (bg->dados[k][i][j] - tolerancia))
                {
                  img->dados[0][i][j] = 0;
                  img->dados[1][i][j] = 0;
                  img->dados[2][i][j] = 0;
                  
                  
                 // img->dados[k][i][j] = 0;
                }
            }
        }
    }
    sprintf (arquivo, "t01.bmp");
    salvaImagem3C (img, arquivo);



/*
    for(i=0; i < img->altura; i ++)
    {
        for(j =0; j < img->largura; j++)
        {
            for(k = 0; k < 3; k++)
            {

                if(img->dados[k][i][j] <( bg->dados[k][i][j] + tolerancia) && img->dados[k][i][j] > (bg->dados[k][i][j] - tolerancia))
                {
                  img->dados[k][i][j] = 0;

                }
            }
        }
    }
    sprintf (arquivo, "passandopelasegundavez.bmp");
    salvaImagem3C (img, arquivo);*/
}
