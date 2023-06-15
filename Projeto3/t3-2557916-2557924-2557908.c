#include <stdio.h>
#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"
#define BUFFER 3000

unsigned int i, j, k;
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

                if(img->dados[i][j][k] == bg->dados[i][j][k])
                {
                  img->dados[i][j][k] = 0x255;

                }
            }
        }
    }
    sprintf (arquivo, "peloamordedeusfunciona.bmp");
    salvaImagem3C (img, arquivo);

}
