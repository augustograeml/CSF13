/*--------------------------------------------------
CSF13 - Projeto 2 - Entrega: 07/06/2023
Augusto César Graeml &  Caique Ferraz
     2557916                2557924
--------------------------------------------------*/
#include "trabalho2.h"
#include<stdio.h>
#include<stdlib.h>

//função 1: muda o ganho do áudio de entrada
void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i; //variável de controle de iteração i

    for(i = 0; i<n_amostras; i++) //loop para percorrer o vetor dados inteiro
    {
        dados[i] = dados[i]*ganho; //multiplica o valor atual do vetor pelo ganho passado como parametro para a função
    }
}

//função 2: mistura dois áudios diferentes em um só
void misturaDados (double* dados1, double* dados2, double* saida, int n_amostras)
{
    int i; //variável de controle de iteração i

    for(i = 0; i < n_amostras; i++) //loop para percorrer o vetor por completo
    {
        saida[i] = dados1[i] + dados2[i];// vetor saída recebe a soma dos dados dos dois vetores de entrada
    }

}

//função 3: inverte o áudio de entrada
void inverteSinal (double* dados, int n_amostras)
{
    int i; //varável de controle de iteração
    double dados_aux; //variável auxiliar que permite que os dados não sejam perdidos durante a inversão

    for(i = 0; i < n_amostras/2; i++)//loop para percorrer até a metade do vetor, uma vez que se for percorrido por inteiro vamos ter erros na inversão
    {
        dados_aux = dados[n_amostras-i-1]; //variável auxiliar recebe e armazena os dados da ultima posição e decresce a cada iteração
        dados[n_amostras-i-1] = dados[i];//a última posição recebe o dado armazenado na primeira posição
        dados[i] = dados_aux; // primeira posição recebe o dado armazenado na variável auxiliar que pertencia a última posição
    }
}

//função 4: atrasa ou adianta o áudio
void atrasaSinal (double* dados, int n_amostras, int atraso)
{
    int i; // variável de controle de iteração

    if(atraso < n_amostras) //condicional para tratar de atrasos menores do que o próprio áudio
    {

        if(atraso > 0) //condicional para tratar de atrasos positivos
        {
            for(i = 0; i<n_amostras-atraso ; i++) //loop para percorrer o áudio até onde será o novo final do áudio
            {
                dados[n_amostras-1-i] = dados[n_amostras-1-i-atraso]; //a última posição recebe os dados armazenados nas posições que serão o novo final
            }
            for(i=0; i<atraso; i++) //loop para preencher a parte do atraso com zeros dando assim o efeito de atraso
                dados[i] = 0.0;

        }
        else if(atraso < 0) //condicional para tratar de atrasos negativos
        {

            for(i = 0; i<n_amostras+atraso; i++) //loop para percorrer até onde será o novo final
            {
                dados[i] = dados[i-atraso]; //posição incial recebe os dados armazenados no novo começo
            }
            for(i=0; i<atraso; i++) //loop para zerar a parte do atraso
                dados[n_amostras-1-i] = 0.0;
        }

    }
    else //condicional para tratar de quando o atraso é maior que o próprio áudio
    {
        for(i = 0; i<n_amostras; i++) //loop para zerar o áudio inteiro
            dados[i] = 0.0;
    }


}
//função 5: aplica um filtro abafando o som
void filtroDaMedia (double* dados, int n_amostras, int largura)
{
    double* valorOriginal = (double*)malloc(n_amostras * sizeof(double)); // vetor para armazenar os valores originais do vetor dados de entrada para poder calcular as médias
    int i, j; //variáveis de controle de iteração e manipulação de vetores
    double media, soma; //variáveis para realizar as operações necessárias para o filtro

    for(i = 0; i< n_amostras; i++)//loop para copiar os dados do vetor dados para o vetor que guarda os valores originais
        valorOriginal[i] = dados[i];

    if(largura > 3 && largura < n_amostras && largura%2==1) //condicional para garantir que a largura não seja maior que o próprio vetor, seja ímpar e maior que três para que o filtro faça sentido
        for(i = 0; i<n_amostras; i++)  //loop para percorrer todas as posições do vetor
        {
            if(i - (largura-1)/2 >= 0 && i+(largura-1)/2 < n_amostras) //condicional para evitar acesso de endereços de memória negativos ou maior que o tamanho original do vetor
            {
                soma = 0.0; //inicializa a soma em 0
                for(j = i - (largura-1)/2; j <= i + (largura-1)/2; j++) //loop para percorrer todos os números contidos na largura e incrementar a variável soma com o seus valores
                {
                    soma += valorOriginal[j];
                }
                media = soma/largura; //cálculo da média
                dados[i] = media; //atualização do vetor original para os valores pós filtro de média
            }
        }
    }
    free(valorOriginal); //desalocação da memória utilizada pelo vetor valorOriginal
}

//função extra: usa 4 das outras funções para criar um efeito de ecos
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso, int abafamento, double decaimento)
{
    int i, j; //variáveis de controle de iteração
    double* dadosCopia = (double*)malloc(n_amostras * sizeof(double)); //vetor que mantém a cópia dos valores do vetor de entrada incial
    double* saida = (double*)malloc(n_amostras * sizeof(double)); //vetor de saída da função

    for(i = 0; i<n_amostras; i++) //loop para a cópia dos valores originais
        dadosCopia[i] = dados[i];

    for(i = 0; i < n_repeticoes; i++) //loop para realizar o eco o tanto de vezes especificado pelo chamador da função
    {
            filtroDaMedia (dadosCopia, n_amostras, abafamento); //aplica o filtro da média no vetor com os dados copiados para o abafamento definido
            mudaGanho (dadosCopia, n_amostras, decaimento); //diminui o som pelo decaimento especificado pelo chamador da função
            atrasaSinal (dadosCopia, n_amostras, atraso); // atrasa o sinal de acordo com o atraso especificado
            misturaDados (dadosCopia, dados, saida, n_amostras); // mistura o vetor que foi modificado com o original causando o efeito de eco e armazena no vetor saída

        for(j = 0; j<n_amostras; j++) //loop para percorrer o vetor inteiro
            dados[j] = saida[j]; //vetor original recebe os valores do vetor de saída
    }

    free(dadosCopia); //desaloca a memória previamente alocada para o vetor dadosCopia
    free(saida); //desaloca a memória previamente alocada para o vetor saida
}
