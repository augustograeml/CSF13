/*------------------------------------------------
AUGUSTO CESAR GRAEML | 2557916
CAIQUE FERRAZ        | 2557924
ANTONIO NETO         | 2557908

PROJETO 3 - Implementação da função contaVeiculos
-------------------------------------------------*/
#include <stdio.h>
#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"
#define BUFFER 3000

//variáveis i, j, k para percorrer as matrizes, tolerancia matém um intervalo como uma margem de erro
int i, j, k;
char arquivo[BUFFER]; //caminho para oa arquivo que será gerado pela função removeFundo
Imagem3C* removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img
int identificaVeiculos (Imagem3C* teste, int* contagem);

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
   int total;

   removeFundo(img, bg);
   total = identificaVeiculos(img, contagem);

   return total;
}

Imagem3C* removeFundo(Imagem3C* img, Imagem3C* bg)
{

    suavizaImagem(img);
    suavizaImagem(bg);

    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*1.45) && img->dados[0][i][j] > (bg->dados[0][i][j]*0.6) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*1.45) && img->dados[1][i][j] > (bg->dados[1][i][j]*0.6) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*1.45) && img->dados[2][i][j] > (bg->dados[2][i][j]*0.6))
            {
                img->dados[0][i][j] = 0;
                img->dados[1][i][j] = 0;
                img->dados[2][i][j] = 0;

                bg->dados[0][i][j] =  0;
                bg->dados[1][i][j] =  0;
                bg->dados[2][i][j] =  0;

            }
        }
    }

    sprintf (arquivo, "t01.bmp");
    salvaImagem3C (img, arquivo);

    sprintf (arquivo, "t01bg.bmp");
    salvaImagem3C (bg, arquivo);

    return img;
}

int identificaVeiculos (Imagem3C* teste, int* contagem)
{
    int cont = 0, soma_total = 0;

    for(i = 0; i < N_TIPOS_DE_VEICULOS; i++)
        contagem[i] = 0;

    for(i = 0; i < teste->altura; i++)
    {
        for(j = 0; j < teste-> largura; j++)
        {
            if((teste->dados[0][i][j] && teste->dados[1][i][j] && teste->dados[2][i][j]) != 0)
                cont++;
            else
            {
                if(cont > 60 && cont <= 72)
                    contagem[0]++;
                else if(cont > 72 && cont <= 102)
                    contagem[1]++;
                else if(cont > 102 && cont <= 302)
                    contagem[2]++;
                else if(cont > 302 && cont <= 390)
                    contagem[3]++;

                cont = 0;

            }
        }
    }
    for(i = 0; i < N_TIPOS_DE_VEICULOS; i++)
        soma_total += contagem[i];

    return soma_total;
}

