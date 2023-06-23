/*------------------------------------------------
ANTONIO NETO         | 2557908
AUGUSTO CESAR GRAEML | 2557916
CAIQUE FERRAZ        | 2557924

PROJETO 3 - Implementação da função contaVeiculos
-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"
#define BUFFER 3000
#define PARAMETRO_SUAVIZACAO 50
#define TAMANHO 3

//variáveis i, j, k para percorrer as matrizes, tolerancia matém um intervalo como uma margem de erro
unsigned int i, j, k, tolerancia = 50;
//unsigned char tolerancia = '0';
char arquivo[BUFFER]; //caminho para oa arquivo que será gerado pela função removeFundo

/*------------------------------------------------------------------------------------*/

void removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img
int verificaControle(Imagem1C* controle);
unsigned char **alocaMatriz (Imagem1C* controle);
void destroiMatriz (Imagem1C* matriz);
int verificaTamanho(int tamanho);

/*------------------------------------------------------------------------------------*/

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
Imagem1C controle;
controle.altura = TAMANHO;
controle.largura = TAMANHO;
controle.dados = alocaMatriz(&controle);

Imagem1C img_simplificada;
img_simplificada.altura = (img->altura)/3;
img_simplificada.largura = (img->largura)/3;
img_simplificada.dados = alocaMatriz(&img_simplificada);

int tem_cor = 0, tamanho = 0, linha = 0, coluna = 0, tem_um = 0;
    removeFundo(img, bg);

    //percorre a imagem com a matriz controle por cima e copia os dados
     for(i=0; i < img->altura; i+=TAMANHO )
    {
        for(j =0; j < img->largura; j+=TAMANHO)
        {
            //preenche a matriz de controle
            for(linha = 0; linha < TAMANHO; linha++)
                for(coluna = 0; coluna < TAMANHO; coluna++)
                    controle.dados[linha][coluna] = img->dados[0][linha][coluna] + img->dados[1][linha][coluna] + img->dados[2][linha][coluna];

            //preenche a matriz img_simplificada
             for(linha = 0; linha < img_simplificada.altura; linha++)
                for(coluna = 0; coluna < img_simplificada.largura; coluna++)
                    img_simplificada.dados[linha][coluna] = verificaControle(&controle);
        }
    }
    sprintf (arquivo, "t01.bmp");
    salvaImagem3C (img, arquivo);

    for(linha = 0; linha < img_simplificada.altura; linha++)
    {
        for(coluna = 0; coluna < img_simplificada.largura; coluna++)
        {
            printf("%d", img_simplificada.dados[linha][coluna]);
        }
        printf("\n");
    }
    for(i = 0; i < img_simplificada.altura; i++)
        for(j = 0 ; j < img_simplificada.largura; j++);
        {
            if(img_simplificada.dados[i][j] != 0)
                tem_um++;
        }

    while(tem_um)
    {
            for(i = 0; i < img_simplificada.altura; i++)
                for(j = 0; j < img_simplificada.largura; j++)
                {
                    if(img->dados[k][i][j] != 0 )
                    {
                        tamanho++;
                        img->dados[i][j] = 0;
                        tem_um--;
                    }
                    int classificacao = verificaTamanho(tamanho); //implementar int verificaTamanho (if's para verificar tamanho se é moto, etc.) retorna 0,1,2,3(posicoes do vetor contagem)

                    if(classificacao == 0)
                       contagem[0]++;
                    else if(classificacao == 1)
                       contagem[1]++;
                    else if(classificacao == 2)
                        contagem[2]++;
                    else
                        contagem[3]++;
                }


return 0;
}

void removeFundo(Imagem3C* img, Imagem3C* bg)
{

    suavizaImagem(img);


    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*1.25) && img->dados[0][i][j] > (bg->dados[0][i][j]*0.75) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*1.25) && img->dados[1][i][j] > (bg->dados[1][i][j]*0.75) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*1.25) && img->dados[2][i][j] > (bg->dados[2][i][j]*0.75))
            {
                img->dados[0][i][j] = 0;
                img->dados[1][i][j] = 0;
                img->dados[2][i][j] = 0;
                 // img->dados[k][i][j] = 0;

                bg->dados[0][i][j] = 0;
                bg->dados[1][i][j] = 0;
                bg->dados[2][i][j] = 0;
            }


        }
    }

    sprintf (arquivo, "t01.bmp");
    salvaImagem3C (img, arquivo);

    sprintf (arquivo, "t01bg.bmp");
    salvaImagem3C (bg, arquivo);
}


int verificaControle(Imagem1C* controle)
{
    int i, j, cont_pretos = 0, cont_coloridos = 0, conta_blocos = 0;


    for(i = 0; i < controle->altura; i++)
    {
        for(j = 0; j < controle->largura; j++)
        {
            conta_blocos++;

            if(!(controle->dados[i][j]))
                cont_coloridos++;
            else
                cont_pretos++;

            if(conta_blocos == TAMANHO*TAMANHO)
            {
                if(cont_coloridos >= cont_pretos)
                    return 1;
                else
                    return 0;
            }

        }
    }

}

unsigned char **alocaMatriz (Imagem1C* controle)
{
    unsigned char **matriz;
    int i;
    matriz = (Imagem1C **) malloc(controle->altura * sizeof (Imagem1C*));
    for(i = 0; i < controle->altura; i++)
        matriz[i] = (Imagem1C *) malloc( controle->largura * sizeof (Imagem1C));

    return matriz;

}

void destroiMatriz (Imagem1C* matriz)
{
    int i;
    for(i = 0; i < matriz->largura; i++)
        free(matriz->dados[i]);

    free (matriz->dados);
}

int verificaTamanho(int tamanho)
{
    int tam_moto = 72/TAMANHO, tam_carro = 102/TAMANHO, tam_caminhao = 302/TAMANHO, tam_caminhaoG = 390/TAMANHO;

    if(tamanho > 3 && tamanho < tam_moto){
        return 0;
    }
    if(tamanho > tam_moto && tamanho < tam_carro){
        return 1;
    }
    if(tamanho > tam_carro && tamanho < tam_caminhao){
        return 2;
    }
    if(tamanho > tam_caminhao && tamanho < tam_caminhaoG){
        return 3;
    }
}
