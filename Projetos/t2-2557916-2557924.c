/*--------------------------------------------------
CSF13 - Projeto 2 - Entrega: 07/06/2023
Augusto C�sar Graeml &  Caique Ferraz
     2557916                2557924
--------------------------------------------------*/
#include "trabalho2.h"
#include<stdio.h>
#include<stdlib.h>

//fun��o 1: muda o ganho do �udio de entrada
void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i; //vari�vel de controle de itera��o i

    for(i = 0; i<n_amostras; i++) //loop para percorrer o vetor dados inteiro
    {
        dados[i] = dados[i]*ganho; //multiplica o valor atual do vetor pelo ganho passado como parametro para a fun��o
    }
}

//fun��o 2: mistura dois �udios diferentes em um s�
void misturaDados (double* dados1, double* dados2, double* saida, int n_amostras)
{
    int i; //vari�vel de controle de itera��o i

    for(i = 0; i < n_amostras; i++) //loop para percorrer o vetor por completo
    {
        saida[i] = dados1[i] + dados2[i];// vetor sa�da recebe a soma dos dados dos dois vetores de entrada
    }

}

//fun��o 3: inverte o �udio de entrada
void inverteSinal (double* dados, int n_amostras)
{
    int i; //var�vel de controle de itera��o
    double dados_aux; //vari�vel auxiliar que permite que os dados n�o sejam perdidos durante a invers�o

    for(i = 0; i < n_amostras/2; i++)//loop para percorrer at� a metade do vetor, uma vez que se for percorrido por inteiro vamos ter erros na invers�o
    {
        dados_aux = dados[n_amostras-i-1]; //vari�vel auxiliar recebe e armazena os dados da ultima posi��o e decresce a cada itera��o
        dados[n_amostras-i-1] = dados[i];//a �ltima posi��o recebe o dado armazenado na primeira posi��o
        dados[i] = dados_aux; // primeira posi��o recebe o dado armazenado na vari�vel auxiliar que pertencia a �ltima posi��o
    }
}

//fun��o 4: atrasa ou adianta o �udio
void atrasaSinal (double* dados, int n_amostras, int atraso)
{
    int i; // vari�vel de controle de itera��o

    if(atraso < n_amostras) //condicional para tratar de atrasos menores do que o pr�prio �udio
    {

        if(atraso > 0) //condicional para tratar de atrasos positivos
        {
            for(i = 0; i<n_amostras-atraso ; i++) //loop para percorrer o �udio at� onde ser� o novo final do �udio
            {
                dados[n_amostras-1-i] = dados[n_amostras-1-i-atraso]; //a �ltima posi��o recebe os dados armazenados nas posi��es que ser�o o novo final
            }
            for(i=0; i<atraso; i++) //loop para preencher a parte do atraso com zeros dando assim o efeito de atraso
                dados[i] = 0.0;

        }
        else if(atraso < 0) //condicional para tratar de atrasos negativos
        {

            for(i = 0; i<n_amostras+atraso; i++) //loop para percorrer at� onde ser� o novo final
            {
                dados[i] = dados[i-atraso]; //posi��o incial recebe os dados armazenados no novo come�o
            }
            for(i=0; i<atraso; i++) //loop para zerar a parte do atraso
                dados[n_amostras-1-i] = 0.0;
        }

    }
    else //condicional para tratar de quando o atraso � maior que o pr�prio �udio
    {
        for(i = 0; i<n_amostras; i++) //loop para zerar o �udio inteiro
            dados[i] = 0.0;
    }


}
//fun��o 5: aplica um filtro abafando o som
void filtroDaMedia (double* dados, int n_amostras, int largura)
{
    double* valorOriginal = (double*)malloc(n_amostras * sizeof(double)); // vetor para armazenar os valores originais do vetor dados de entrada para poder calcular as m�dias
    int i, j; //vari�veis de controle de itera��o e manipula��o de vetores
    double media, soma; //vari�veis para realizar as opera��es necess�rias para o filtro

    for(i = 0; i< n_amostras; i++)//loop para copiar os dados do vetor dados para o vetor que guarda os valores originais
        valorOriginal[i] = dados[i];

    if(largura > 3 && largura < n_amostras && largura%2==1) //condicional para garantir que a largura n�o seja maior que o pr�prio vetor, seja �mpar e maior que tr�s para que o filtro fa�a sentido
        for(i = 0; i<n_amostras; i++)  //loop para percorrer todas as posi��es do vetor
        {
            if(i - (largura-1)/2 >= 0 && i+(largura-1)/2 < n_amostras) //condicional para evitar acesso de endere�os de mem�ria negativos ou maior que o tamanho original do vetor
            {
                soma = 0.0; //inicializa a soma em 0
                for(j = i - (largura-1)/2; j <= i + (largura-1)/2; j++) //loop para percorrer todos os n�meros contidos na largura e incrementar a vari�vel soma com o seus valores
                {
                    soma += valorOriginal[j];
                }
                media = soma/largura; //c�lculo da m�dia
                dados[i] = media; //atualiza��o do vetor original para os valores p�s filtro de m�dia
            }
        }
    }
    free(valorOriginal); //desaloca��o da mem�ria utilizada pelo vetor valorOriginal
}

//fun��o extra: usa 4 das outras fun��es para criar um efeito de ecos
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso, int abafamento, double decaimento)
{
    int i, j; //vari�veis de controle de itera��o
    double* dadosCopia = (double*)malloc(n_amostras * sizeof(double)); //vetor que mant�m a c�pia dos valores do vetor de entrada incial
    double* saida = (double*)malloc(n_amostras * sizeof(double)); //vetor de sa�da da fun��o

    for(i = 0; i<n_amostras; i++) //loop para a c�pia dos valores originais
        dadosCopia[i] = dados[i];

    for(i = 0; i < n_repeticoes; i++) //loop para realizar o eco o tanto de vezes especificado pelo chamador da fun��o
    {
            filtroDaMedia (dadosCopia, n_amostras, abafamento); //aplica o filtro da m�dia no vetor com os dados copiados para o abafamento definido
            mudaGanho (dadosCopia, n_amostras, decaimento); //diminui o som pelo decaimento especificado pelo chamador da fun��o
            atrasaSinal (dadosCopia, n_amostras, atraso); // atrasa o sinal de acordo com o atraso especificado
            misturaDados (dadosCopia, dados, saida, n_amostras); // mistura o vetor que foi modificado com o original causando o efeito de eco e armazena no vetor sa�da

        for(j = 0; j<n_amostras; j++) //loop para percorrer o vetor inteiro
            dados[j] = saida[j]; //vetor original recebe os valores do vetor de sa�da
    }

    free(dadosCopia); //desaloca a mem�ria previamente alocada para o vetor dadosCopia
    free(saida); //desaloca a mem�ria previamente alocada para o vetor saida
}
