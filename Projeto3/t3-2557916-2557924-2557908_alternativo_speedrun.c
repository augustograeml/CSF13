/*------------------------------------------------
AUGUSTO CESAR GRAEML | 2557916
CAIQUE FERRAZ        | 2557924
ANTONIO NETO         | 2557908

PROJETO 3 - Implementação da função contaVeiculos
-------------------------------------------------*/

#include "gerador_de_testes.h"
#include "imagem.h"
#include "trabalho3.h"

//variáveis i, j, k para percorrer as matrizes
int i, j, k;
Imagem3C* removeFundo(Imagem3C* img, Imagem3C* bg); //função para remover o fundo da img
int identificaVeiculos (Imagem3C* teste, Imagem3C* bg, int* contagem);
void suavizaImagem (Imagem3C* img);

//funcao que chama outras funcoes pra contar veiculos
int contaVeiculos (Imagem3C* img, Imagem3C* bg, int contagem [N_TIPOS_DE_VEICULOS])
{
   int total;

   removeFundo(img, bg);
   total = identificaVeiculos(img, bg, contagem);

   return total;
}

//funcao que remove o fundo pra nao atrapalhar na contagem dos carros
Imagem3C* removeFundo(Imagem3C* img, Imagem3C* bg)
{

    //chamamos a funcao suaviza pra reduzir o ruido tanto do background quanto da imagem padrao
    suavizaImagem(img);
    suavizaImagem(bg);

    //um valor de tolerancia que sera usado para evitar ao maximo que os veiculos sejam afetados quando a gente remove o fundo da imagem
    int tolerancia = 20;


    //um loop que eh usado pra retirar sem afetar os veiculos o fundo da imagem transformando o que entrar na condicao em preto
    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] < (bg->dados[0][i][j]*1.289) && img->dados[0][i][j] > (bg->dados[0][i][j]*0.73) &&
               img->dados[1][i][j] < (bg->dados[1][i][j]*1.289) && img->dados[1][i][j] > (bg->dados[1][i][j]*0.73) &&
               img->dados[2][i][j] < (bg->dados[2][i][j]*1.289) && img->dados[2][i][j] > (bg->dados[2][i][j]*0.73))
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

    //loop usado pra mudar de cor (qualquer uma diferente de preto) o que tem dentro dos veiculos quando os valores dos pixeis deles forem afetados
    for(i=0; i < img->altura; i ++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(img->dados[0][i][j] >= (bg->dados[0][i][j] - tolerancia) && img->dados[0][i][j] >= (bg->dados[0][i][j] + tolerancia) &&
               img->dados[1][i][j] >= (bg->dados[1][i][j] - tolerancia) && img->dados[1][i][j] >= (bg->dados[1][i][j] + tolerancia) &&
               img->dados[2][i][j] >= (bg->dados[2][i][j] - tolerancia) && img->dados[2][i][j] >= (bg->dados[2][i][j] + tolerancia))
            {
                img->dados[0][i][j] = 144;
                img->dados[1][i][j] = 238;
                img->dados[2][i][j] = 144;

                bg->dados[0][i][j] =  144;
                bg->dados[1][i][j] =  238;
                bg->dados[2][i][j] =  144;

            }
        }
    }

    //loop usado para transformar a grama em preto, para nao atrapalhar a contagem dos veiculos (grama de cima)
    for(i=0; i < 94; i++)
        for(j=0; j < img->largura; j++)
            for(k = 0; k < 3; k++)
                bg->dados[k][i][j] = 0;

    //loop usado para transformar a grama em preto, para nao atrapalhar a contagem dos veiculos (grama de baixo)
    for(i=674; i < img->altura; i++)
        for(j=0; j < img->largura; j++)
            for(k = 0; k < 3; k++)
                bg->dados[k][i][j] = 0;

    //loop usado para transformar o teto do pedagio em preto, para nao atrapalhar a contagem dos veiculos
    for(i=0; i < img->altura; i++)
        for(j = 959; j < img->largura; j++)
            for(k = 0; k < 3; k++)
                bg->dados[k][i][j] = 0;

    return img;
}

//funcao que conta os carros de fato
int identificaVeiculos (Imagem3C* teste, Imagem3C* bg, int* contagem)
{
    //sao declaradas variaveis pra contar a quantidade de pixels de um determinado veiculo e a soma total de todos os veiculos
    int cont = 0, soma_total = 0;

    //loop q zera a contagem dos veiculos pra limpar um possivel lixo no vetor de contagem
    for(i = 0; i < N_TIPOS_DE_VEICULOS; i++)
        contagem[i] = 0;

    //loop que passa no meio de cada faixa pra contar todos os veiculos, tirando as motos
    //a sequencia de condicoes serve para analisar o entorno de um pixel para que os pixeis sejam contados corretamente
    for(i = 134; i < (teste->altura - 94); i+=100)
    {
        for(j = 0; j < 909; j++)
        {
            if((bg->dados[0][i][j] || bg->dados[1][i][j] || bg->dados[2][i][j]) != 0)
                cont++;

            else if((bg->dados[0][i][j+1] || bg->dados[1][i][j+1] || bg->dados[2][i][j+1]) != 0)
                cont++;

            else if((bg->dados[0][i][j+2] || bg->dados[1][i][j+2] || bg->dados[2][i][j+2]) != 0)
                cont++;

            else if((bg->dados[0][i][j+3] || bg->dados[1][i][j+3] || bg->dados[2][i][j+3]) != 0)
                cont++;

            else if((bg->dados[0][i-1][j] || bg->dados[1][i-1][j] || bg->dados[2][i-1][j]) != 0)
                cont++;

            else if((bg->dados[0][i-1][j+1] || bg->dados[1][i-1][j+1] || bg->dados[2][i-1][j+1]) != 0)
                cont++;

            else if((bg->dados[0][i+1][j] || bg->dados[1][i+1][j] || bg->dados[2][i+1][j]) != 0)
                cont++;

            else if((bg->dados[0][i-1][j-1] || bg->dados[1][i-1][j] || bg->dados[2][i-1][j-1]) != 0)
                cont++;

            //onde o vetor de contagem eh incrementado de acordo com seu tamanho
            else
            {
                if(cont > 81 && cont <= 140)
                    contagem[1]++;
                else if(cont > 140 && cont <= 320)
                    contagem[2]++;
                else if(cont > 320 && cont <= 400)
                    contagem[3]++;

                cont = 0;

            }
        }
    }

    cont = 0;

    //loop que passa na parte de baixo de cada faixa pra contar somente as motos
    //a sequencia de condicoes serve para analisar o entorno de um pixel para que os pixeis sejam contados corretamente
    for(i = 151; i < (teste->altura - 84); i+=100)
    {
        for(j = 0; j < 909; j++)
        {
            if((bg->dados[0][i][j] || bg->dados[1][i][j] || bg->dados[2][i][j]) != 0)
                cont++;

            else if((bg->dados[0][i][j+1] || bg->dados[1][i][j+1] || bg->dados[2][i][j+1]) != 0)
                cont++;

            else if((bg->dados[0][i][j+2] || bg->dados[1][i][j+2] || bg->dados[2][i][j+2]) != 0)
                cont++;

            else if((bg->dados[0][i][j+3] || bg->dados[1][i][j+3] || bg->dados[2][i][j+3]) != 0)
                cont++;

            else if((bg->dados[0][i-1][j] || bg->dados[1][i-1][j] || bg->dados[2][i-1][j]) != 0)
                cont++;

            else if((bg->dados[0][i-1][j+1] || bg->dados[1][i-1][j+1] || bg->dados[2][i-1][j+1]) != 0)
                cont++;

            else if((bg->dados[0][i+1][j] || bg->dados[1][i+1][j] || bg->dados[2][i+1][j]) != 0)
                cont++;

            //onde o vetor de contagem eh incrementado somente para as motos
            else
            {
                if(cont > 55 && cont <= 85)
                    contagem[0]++;

                cont = 0;
            }
        }
    }

    //calcula a quantidade total de veiculos contados
    for(i = 0; i < N_TIPOS_DE_VEICULOS; i++)
        soma_total += contagem[i];

    return soma_total;
}
