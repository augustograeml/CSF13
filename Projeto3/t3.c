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
#define RESUMO 8

//variáveis i, j, k para percorrer as matrizes, tolerancia matém um intervalo como uma margem de erro

//unsigned char tolerancia = '0';
char arquivo[BUFFER]; //caminho para oa arquivo que será gerado pela função removeFundo

/*------------------------------------------------------------------------------------*/

void removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img
void filtroDeImagem (Imagem3C* img, int tamanho_vizinhos);
int num_vizinhos(Imagem3C* img,int k, int i, int j);
void rotulaCarros (int** matrizResumida, int altura, int largura, int** matriz);
void zeraIndividuais (int i, int j, int** matriz_resumida);

/*------------------------------------------------------------------------------------*/

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
int altura = img->altura;
int largura = img->largura;
int** matriz_binaria;
int cont = 0, i, j;

int v = 2;

    removeFundo(img, bg);

    for( i = 0; i < 3; i++)
    {
        filtroDeImagem(img, v);
    }

    sprintf (arquivo, "teste2.bmp");
			salvaImagem3C (img, arquivo);

    matriz_binaria = (int**) malloc (sizeof(int*) * altura);

    for(i = 0; i<altura; i++)
        matriz_binaria[i] = (int*) malloc(sizeof(int) * largura);

    for(i = 0; i<altura; i++)
        for(j = 0; j<largura; j++)
            if(img->dados[0][i][j] != 0)
            {
                matriz_binaria[i][j] = 1;
            }
            else
                matriz_binaria[i][j] = 0;

    int** matrizResumida = (int**) malloc(sizeof(int*) * altura/RESUMO);

    for(i = 0; i<altura/RESUMO; i++)
        matrizResumida[i] = (int*)malloc (sizeof(int)* largura/RESUMO);

    rotulaCarros(matrizResumida, altura, largura, matriz_binaria);


    for(i = 0; i<4; i++)
        contagem[i] = 0;


    int bele = 0;
    int n_linhas = 0;


    for(int k = 2; k<50; k++)
        {
            for(i = 0; i<altura/RESUMO; i++)
                for(j = 0; j<largura/RESUMO; j++)
                {
                    if(matrizResumida[i][j] == k)
                    {
                        n_linhas++;
                        while(matrizResumida[i][j+bele] != 0)
                        {
                            cont++;
                            bele++;
                        }
                        bele = 0;

                    }
                }
            if(n_linhas < 2)
                cont = 0;

            n_linhas = 0;

            //printf("%d: %d\n", k, cont);

            if(cont>=12 && cont<=30)
                contagem[0]++;
            else if(cont>=40 && cont<=120)
                contagem[1]++;
            else if(cont>=130 && cont<=370)
                contagem[2]++;
            else if(cont>=371 && cont<=500)
                contagem[3]++;
            cont = 0;

        }

        int total = 0;

        for(i = 0; i<4; i++)
            total += contagem[i];

    for(i = 0;i<altura; i++)
        free(matriz_binaria[i]);
    free(matriz_binaria);

    for(i = 0; i<altura/RESUMO; i++)
        free(matrizResumida[i]);
    free(matrizResumida);

    return total;
}

void removeFundo(Imagem3C* img, Imagem3C* bg)
{
    int i, j, k;
    suavizaImagem(img);
    suavizaImagem(bg);


    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*1.5) && img->dados[0][i][j] > (bg->dados[0][i][j]*0.76) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*1.5) && img->dados[1][i][j] > (bg->dados[1][i][j]*0.76) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*1.5) && img->dados[2][i][j] > (bg->dados[2][i][j]*0.76))
            {
                img->dados[0][i][j] = 0;
                img->dados[1][i][j] = 0;
                img->dados[2][i][j] = 0;

        
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
    //loop para tirar a grama 100 = tamanho da grama
    for( i =0; i < 100; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
            for(k=0; k < 3; k++)
                img->dados[k][i][j] = 0;

        }


    }
    for(i = 675; i < img->altura; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
           for(k = 0; k < 3; k++)
                img->dados[k][i][j] = 0;
        }
    }


}



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

void rotulaCarros (int** matrizResumida, int altura, int largura, int** matriz)
{
    int tem = 0, flag, rotulo = 2, k, i, j, achou_acima = 0;

    for(i = 0; i<altura/RESUMO; i++)
        for(j = 0;j<largura/RESUMO; j++)
        {
            matrizResumida[i][j] = matriz[i*RESUMO][j*RESUMO];
        }

    for(i = 1; i<(altura/RESUMO)-1; i++)
        for(j = 1; j<(largura/RESUMO)-1; j++)
        {
            flag = 1;
            if(matrizResumida[i][j] == 1)
            {
                zeraIndividuais(i, j, matrizResumida);
                if(matrizResumida[i][j-1] == 0 && matrizResumida[i][j+1] == 0)
                    matrizResumida[i][j] = 0;

                for(int h = 0; h<3; h++)
                {
                    if(j+h < largura/RESUMO && matrizResumida[i][j+h] == 0)
                    {
                        flag = 0;
                        break;
                    }

                }

                if(tem == 0 && flag == 1)
                {
                    tem = 1;

                    if(matrizResumida[i-1][j] == 0)
                    {
                        for(k = 0; k<7; k++)
                        {
                            if (j+k<=largura/RESUMO)
                            {
                                if(matrizResumida[i-1][j+k] != 0 && matrizResumida[i-1][j+k] != 1)
                                {
                                    matrizResumida[i][j] = matrizResumida[i-1][j+k];
                                    achou_acima = 1;
                                    break;
                                }
                            }
                        }
                        if(achou_acima == 0)
                        {
                            matrizResumida[i][j] = rotulo;
                            rotulo++;
                        }

                        achou_acima = 0;
                    }
                    else if(matrizResumida[i-1][j] == 1)
                        for(k = 0; k<30; k++)
                        {
                            if (j-k>=0)
                            {
                                if(matrizResumida[i-1][j-k] != 0 && matrizResumida[i-1][j-k] != 1)
                                {
                                    matrizResumida[i][j] = matrizResumida[i-1][j-k];
                                    break;
                                }
                            }
                        }
                    else
                        matrizResumida[i][j] = matrizResumida[i-1][j];
                }
            }
            else if (matrizResumida[i][j] == 0)
                tem = 0;
        }
        /*for(i = 0; i<altura/RESUMO; i++)
        {
            for(j = 0; j<largura/RESUMO; j++)
                printf("%d", matrizResumida[i][j]);
            printf("\n");
        }*/

}

void zeraIndividuais (int i, int j, int** matriz_resumida)
{

    if (matriz_resumida[i][j-1] == 0 && matriz_resumida[i][j+1] == 0)
        matriz_resumida[i][j] = 0;

    if (matriz_resumida[i][j-1] == 0 && matriz_resumida[i][j+1] == 1 && matriz_resumida[i][j+2] == 0)
    {
        matriz_resumida[i][j] = 0;
        matriz_resumida[i][j+1] = 0;
    }
    if (matriz_resumida[i][j-1] == 0 && matriz_resumida[i][j+1] == 1 && matriz_resumida[i][j+2] == 1 && matriz_resumida[i][j+3] == 0)
    {
        matriz_resumida[i][j] = 0;
        matriz_resumida[i][j+1] = 0;
        matriz_resumida[i][j+2] = 0;
    }

}


