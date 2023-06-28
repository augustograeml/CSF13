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
#define TAMANHO 8
#define LARGURACONE 15

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
void filtroDeImagem (Imagem3C* img, int tamanho_vizinhos);
int num_vizinhos(Imagem3C* img,int k, int i, int j);
int rotulaMatriz(unsigned char** matriz_binaria, int altura, int largura);

/*------------------------------------------------------------------------------------*/

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
int i, j;
int altura = img->altura;
int largura = img->largura;
unsigned char matriz_binaria[altura][largura];
unsigned long max_veiculos;
//zera o vetor contagem
for(i = 0; i < 4; i ++)
    contagem[i] = 0;

int tamanho = 0, linha = 0, coluna = 0, v = 1;
    removeFundo(img, bg);
    //passa o filtro de imagem 20 vezes (valor obtido de maneira experimental)
    for( i = 0; i < 20; i++)
    {
        filtroDeImagem(img, v);
    }

    //percorre as duas matrizes e preenche a matriz_binaria
     for(i=0; i < img->altura; i++ )
    {
        for(j =0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] == 0)
                matriz_binaria[i][j] = 0;
            else
                matriz_binaria[i][j] = 255;

        }

    }
    //max_veiculos = rotulaMatriz(matriz_binaria, altura, largura);

    sprintf (arquivo, "aafiltrodeimagem0.bmp");
    salvaImagem3C (img, "aafiltrodeimagem0.bmp");

    for( i = 0; i < 15; i++)
    {
        filtroDeImagem(img, v);
    }
    sprintf (arquivo, "aafiltrodeimagem1.bmp");
    salvaImagem3C (img, arquivo);




   /* for(linha = 0; linha < img_simplificada.altura; linha++)
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
}*/
//free(img_simplificada.dados);
return 0;
}

void removeFundo(Imagem3C* img, Imagem3C* bg)
{

    suavizaImagem(img);
    suavizaImagem(bg);


    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*1.75) && img->dados[0][i][j] > (bg->dados[0][i][j]*0.75) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*1.75) && img->dados[1][i][j] > (bg->dados[1][i][j]*0.75) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*1.75) && img->dados[2][i][j] > (bg->dados[2][i][j]*0.75))
            {
                img->dados[0][i][j] = 0;
                img->dados[1][i][j] = 0;
                img->dados[2][i][j] = 0;

                 // img->dados[k][i][j] = 0;

                bg->dados[0][i][j] = 0;
                bg->dados[1][i][j] = 0;
                bg->dados[2][i][j] = 0;
            }
            else
            {
                img->dados[0][i][j] = 255;
                img->dados[1][i][j] = 255;
                img->dados[2][i][j] = 255;

            }


        }
    }
    //loop para tirar a grama 84 = tamanho da grama
    for( i =0; i < 84; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
            for(k=0; k < 3; k++)
                img->dados[k][i][j] = 0;

        }


    }
    for(i = 684; i < img->altura; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
           for(k = 0; k < 3; k++)
                img->dados[k][i][j] = 0;
        }
    }
    sprintf (arquivo, "t02.bmp");
    salvaImagem3C (img, arquivo);

    sprintf (arquivo, "t02bg.bmp");
    salvaImagem3C (bg, arquivo);
}



/*int verificaArea (unsigned char** matriz_binaria, int altura, int largura)
{
    int area_max_moto = 5472, area_max_carro = 10980, area_maxt_caminhao = 33220, area_max_caminhaoG = 40560;

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
}}*/

//Procura pontos pretos na imagem e verifica se os vizinhos são brancos
void filtroDeImagem (Imagem3C* img, int tamanho_vizinhos)
{
int i, j, rotulo = 1, k =0;
  for(i = 0; i < img->altura ; i++)
    for(j = 0; j < img->largura ; j++)
    {
        for(k = 0; k < 3; k++)
        {
          if(i + tamanho_vizinhos < img->altura && j+tamanho_vizinhos < img->largura && i-tamanho_vizinhos > 0 && j - tamanho_vizinhos > 0)
          {
            if(img->dados[k][i][j] == 0 && num_vizinhos(img, k, i, j) == 1)
            {
                img->dados[k][i][j] = 255;
                img->dados[k][i+1][j] = 255;
                img->dados[k][i+1][j+1] = 255;
                img->dados[k][i+1][j-1] = 255;
                img->dados[k][i-1][j] = 255;
                img->dados[k][i-1][j-1] = 255;
                img->dados[k][i-1][j+1] = 255;
                img->dados[k][i][j+1] = 255;
                img->dados[k][i][j-1] = 255;
            }
            else if(img->dados[k][i][j] == 255 && num_vizinhos(img, k, i, j) == 2)
            {
                img->dados[k][i][j] = 0;
                img->dados[k][i+1][j] = 0;
                img->dados[k][i+1][j+1] = 0;
                img->dados[k][i+1][j-1] = 0;
                img->dados[k][i-1][j] = 0;
                img->dados[k][i-1][j-1] = 0;
                img->dados[k][i-1][j+1] = 0;
                img->dados[k][i][j+1] = 0;
                img->dados[k][i][j-1] = 0;
            }
          }
        }
    }
}
int num_vizinhos(Imagem3C* img,int k, int i, int j)
{
    int cont = 0;

    if(img->dados[k][i+1][j] == 255)
        cont++;
    if(img->dados[k][i-1][j] == 255)
        cont++;
    if(img->dados[k][i][j+1] == 255)
        cont++;
    if(img->dados[k][i][j-1] == 255)
        cont++;
    if(img->dados[k][i+1][j+1] == 255)
        cont++;
    if(img->dados[k][i+1][j-1] == 255)
        cont++;
    if(img->dados[k][i-1][j+1] == 255)
        cont++;
    if(img->dados[k][i-1][j-1] == 255)
        cont++;

    if(cont > 4)
        return 1;
    //se tiver dois vizinhos brancos
    else if (cont == 2)
        return 2;
    //se tiver apenas um vizinho branco
    else if (cont == 1)
        return 2;
    //se não tiver nenhum vizinho branco
    else if (cont == 0)
        return 2;
    else
        return 0;
}
//procura um pixel que não seja preto verifica os vizinhos de cima em busca de um rótulo menor e então rotula as posições diferentes de 0
int rotulaMatriz(unsigned char** matriz_binaria, int altura, int largura)
{
    int i, j, rotulo = 1;
    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura ; j++)
        {
            if(j - 1 > 0 && j + 1 < largura)
            //equanto achar pixels brancos (veiculos ou cones)
            while(matriz_binaria[i][j] != 0)
            {
                if(matriz_binaria[i-1][j-1] != 0  && matriz_binaria[i-1][j-1] < rotulo)
                {
                    matriz_binaria[i][j] = matriz_binaria[i -1][j -1];
                }
                else if(matriz_binaria[i-1][j] != 0  && matriz_binaria[i-1][j] < rotulo)
                {
                    matriz_binaria[i][j] = matriz_binaria[i -1][j];
                }
                else if(matriz_binaria[i-1][j + 1] != 0  && matriz_binaria[i-1][j + 1] < rotulo)
                {
                    matriz_binaria[i][j] = matriz_binaria[i -1][j + 1];
                }
                else
                {
                    matriz_binaria[i][j] = rotulo;
                }
            }
            rotulo++;
        }
    }
    return rotulo;
}

