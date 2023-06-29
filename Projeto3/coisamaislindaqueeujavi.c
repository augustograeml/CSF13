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
#define RESUMO 8 //em quantas vezes a matriz resumida sera diminuida
#define GRAMA 100
#define MIN_MOTO 12
#define MAX_MOTO 30
#define MAX_MEDIO 120
#define MAX_LONGO 370
#define MAX_LONGO2 500
#define TOLERANCIA_MAX 1.5
#define TOLERANCIA_MIN 0.76
#define TAMANHO_MINIMO 3
#define MAX_ROTULO_ESQ 30
#define MAX_ROTULO_DIR 7

/*------------------------------------------------------------------------------------*/

void removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img
void filtroDeImagem (Imagem3C* img, int tamanho_vizinhos); //função que filtra os ruídos da imagem sem fundo
int num_vizinhos(Imagem3C* img,int k, int i, int j);
void rotulaCarros (int** matrizResumida, int altura, int largura, int** matriz); //função para rotular os veículos
void zeraIndividuais (int i, int j, int** matriz_resumida); //função para zerar 1's em grupos de até 3
int** alocaMatriz (int altura, int largura); //função para alocar matriz dinamicamente
void destroiMatriz(int** matriz, int altura); //função para desalocar matriz

/*------------------------------------------------------------------------------------*/

int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
int i, j, k;
int altura = img->altura;
int largura = img->largura;
int alturaSimpl = altura/RESUMO; //altura para matriz simplificada
int larguraSimpl = largura/RESUMO; //largura para matriz simplificada
int** matriz_binaria;
int** matrizResumida;
int area = 0, incrementador = 0, n_linhas = 0, total_veiculos = 0;
int vizinhos = 2;

    removeFundo(img, bg);

    for(i = 0; i < 3; i++)
    {
        filtroDeImagem(img, vizinhos);
    }

    for(i = 0; i<4; i++)
        contagem[i] = 0;

    matriz_binaria = alocaMatriz(altura, largura);

    //matriz_binaria é comparada com a matriz original e recebe 1 onde há carros e 0 onde há fundo
    for(i = 0; i<altura; i++)
        for(j = 0; j<largura; j++)
            if(img->dados[0][i][j] != 0)
                matriz_binaria[i][j] = 1;
            else
                matriz_binaria[i][j] = 0;


    matrizResumida = alocaMatriz(alturaSimpl, larguraSimpl);

    rotulaCarros(matrizResumida, altura, largura, matriz_binaria);


    //loop que busca os rótulos dentro da matriz resumida e soma suas áreas
    for(k = 2; k<50; k++)
    {
        for(i = 0; i < alturaSimpl; i++)
            for(j = 0; j < larguraSimpl; j++)
            {
                if(matrizResumida[i][j] == k)
                {
                    n_linhas++;

                    /*procura e soma o número de algarismos a partir do
                    rótulo até chegar em 0, assim chegando em sua área total*/
                    while(matrizResumida[i][j+incrementador] != 0)
                    {
                        area++;
                        incrementador++;
                    }
                    incrementador = 0;

                }
            }
        if(n_linhas < 2)
            area = 0;

        n_linhas = 0;

        if(area >= MIN_MOTO && area <= MAX_MOTO)
            contagem[0]++;
        else if(area > MAX_MOTO && area<=MAX_MEDIO)
            contagem[1]++;
        else if(area > MAX_MEDIO && area<=MAX_LONGO)
            contagem[2]++;
        else if(area > MAX_LONGO && area<=MAX_LONGO2)
            contagem[3]++;

        area = 0;
    }

    for(i = 0; i<4; i++)
        total_veiculos += contagem[i];

    destroiMatriz(matriz_binaria, altura);
    destroiMatriz(matrizResumida, alturaSimpl);

    return total_veiculos;
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
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*TOLERANCIA_MAX) && img->dados[0][i][j] > (bg->dados[0][i][j]*TOLERANCIA_MIN) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*TOLERANCIA_MAX) && img->dados[1][i][j] > (bg->dados[1][i][j]*TOLERANCIA_MIN) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*TOLERANCIA_MAX) && img->dados[2][i][j] > (bg->dados[2][i][j]*TOLERANCIA_MIN))
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
    //loop para tirar a grama
    for( i =0; i < GRAMA; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
            for(k=0; k < 3; k++)
                img->dados[k][i][j] = 0;

        }


    }
    for(i = img->altura-GRAMA; i < img->altura; i++)
    {
        for(j = 0; j <=img->largura;j++)
        {
           for(k = 0; k < 3; k++)
                img->dados[k][i][j] = 0;
        }
    }
}

int** alocaMatriz(int altura, int largura)
{
    int i;
    int **matriz;

    matriz = (int**) malloc(sizeof(int*) * altura);

    for(i = 0; i<altura; i++)
        matriz[i] = (int*) malloc(sizeof(int) * largura);

    return matriz;
}

void destroiMatriz(int** matriz, int altura)
{
    int i;

    for(i = 0; i<altura; i++)
        free(matriz[i]);

    free(matriz);
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
/*Função para rotular a matriz simplificada, contendo 0 onde não há carros e 1 onde
há carros, a função só ira rotular o primeiro algarismo de cada linha do veículo,
ex: 000021111100000000000
    000211111000000311100
    000002111100000031100*/
void rotulaCarros (int** matrizResumida, int altura, int largura, int** matriz)
{
    int k, i, j;
    int achou_primeiro_um = 0, eh_continua = 1, achou_acima = 0;
    int rotulo = 2;
    int alturaResumida = altura/RESUMO;
    int larguraResumida = largura/RESUMO;

    //Percorre e copia a matriz original de uma forma reduzida, deixando mais fácil de tratar
    for(i = 0; i<alturaResumida; i++)
        for(j = 0;j<larguraResumida; j++)
        {
            matrizResumida[i][j] = matriz[i*RESUMO][j*RESUMO];
        }

    for(i = 1; i<(alturaResumida)-1; i++)
        for(j = 1; j<(larguraResumida)-1; j++)
        {
            eh_continua = 1;
            if(matrizResumida[i][j] == 1)
            {
                zeraIndividuais(i, j, matrizResumida); //Zera os 010's, 0110's e 01110's presentes na matriz que podem conflitar na lógica de rotulação

                for(int h = 0; h<TAMANHO_MINIMO; h++) //Verifica se a linha de 1's contém o tamanho minimo para ser rotulada
                    if(j+h < larguraResumida && matrizResumida[i][j+h] == 0)
                    {
                        eh_continua = 0;
                        break;
                    }

                /*Se a linha conter o tamanho mínimo para ser rotulada, verifica se na posição acima existe um 0, 1,
                ou outro rótulo, procurando possíveis rótulos já atribuidos ao veículo atual*/
                if(achou_primeiro_um == 0 && eh_continua == 1)
                {
                    achou_primeiro_um = 1;

                    if(matrizResumida[i-1][j] == 0)
                    {
                    /*Se a posição acima for 0, a posição atual pode ser o início de um
                    novo veículo ou uma linha maior que a última em um veículo já rotulado,
                    assim procura-se o rotulo à direita na linha acima*/
                        for(k = 0; k<MAX_ROTULO_DIR; k++)
                            if (j+k<=larguraResumida)
                                if(matrizResumida[i-1][j+k] != 0 && matrizResumida[i-1][j+k] != 1)
                                {
                                    matrizResumida[i][j] = matrizResumida[i-1][j+k];
                                    achou_acima = 1;
                                    break;
                                }
                    /*Se não achou um rótulo acima, atribui um novo rótulo ao novo veículo*/
                        if(achou_acima == 0)
                        {
                            matrizResumida[i][j] = rotulo;
                            rotulo++;
                        }
                        achou_acima = 0;
                    }
                    else if(matrizResumida[i-1][j] == 1)
                    {
                    /*Se a posição acima for 1, a posição atual só pode ser uma linha de um
                    carro já rotulado, assim procura-se o rótulo à esquerda na linha acima*/
                        for(k = 0; k<MAX_ROTULO_ESQ; k++)
                            if (j-k>=0)
                                if(matrizResumida[i-1][j-k] != 0 && matrizResumida[i-1][j-k] != 1)
                                {
                                    matrizResumida[i][j] = matrizResumida[i-1][j-k];
                                    break;
                                }
                    }
                    /*Se a posição acima não for 1 nem 0, só resta ser o rótulo já atribuido*/
                    else
                        matrizResumida[i][j] = matrizResumida[i-1][j];
                }
            }
            else if (matrizResumida[i][j] == 0)
                achou_primeiro_um = 0;
        }
}

//Função para zerar 1's em grupos de até 3, ex: 010, 0110, 0110
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
