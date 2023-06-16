#include <stdio.h>
#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"
#define BUFFER 3000

//variáveis i, j, k para percorrer as matrizes, tolerancia matém um intervalo como uma margem de erro
unsigned int i, j, k, tolerancia = 30;
//unsigned char tolerancia = '0';
char arquivo[BUFFER]; //caminho para oa aarquivo que será gerado pela função removeFundo
void removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{

int tem_cor = 0, tamanho = 0;
    removeFundo(img, bg);

    for(i = 0; i < img->altura; i++)
        for(j = 0; j < img->largura; j++)
            for(k = 0 ; k < 3; k++);
            {
                if(img->dados[k][i][j] != 0)
                    tem_cor++;
            }
        }
    while(tem_cor)
    {
        for(k = 0 ; k < 3; k++)
            for(j = 0; j < img->largura; j++)
                for(i = 0; i < img->altura; i++)
                {
                    if(img->dados[k][i][j] != 0 )
                    {
                        tamanho++;
                        img->dados[k][i][j] = 0;
                    }
                    classificacao = verificaTamanho(tamanho); //implementar int verificaTamanho (if's para verificar tamanho se é moto, etc.) retorna 0,1,2,3(posicoes do vetor contagem)

                    if(classificacao == 0)
                       contagem[0]++;
                    else if(classificacao == 1)
                       contagem[1]++;
                    else if(classificacao == 2)
                        contagem[2]++;
                    else
                        contagem[3]++;
                }


    }



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
int verificaTamanho (int tamanho)
{
    if(tamanho > 5 && tamanho < )



}
