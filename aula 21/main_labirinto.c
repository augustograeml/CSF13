/*===========================================================================*/
/* LABIRINTO                                                                 */
/*===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================================*/

#define FILENAME "/home/todos/alunos/ct/a2557916/Desktop/aula 21/labirinto/teste2.txt"
#define CLEAR "clear" // Mude para "clear" no Linux.

#define BUFLEN 1024 // Altura/largura m�xima do labirinto + 2

#define PAREDE -2
#define CAMINHO -1

/*===========================================================================*/
/* TIPOS                                                                     */
/*===========================================================================*/

typedef struct
{
    int** mat;
    int w;
    int h;

} Labirinto;

/*---------------------------------------------------------------------------*/

typedef struct
{
    int x;
    int y;

} Coordenada2D;

/*===========================================================================*/
/* FUN��ES                                                                   */
/*===========================================================================*/

Labirinto* carregaLabirinto (char* filename, Coordenada2D* rato, Coordenada2D* queijo);
void destroiLabirinto (Labirinto* lab);
void mostraLabirinto (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D pos_queijo);
void preencheMatrizCusto (Labirinto* lab, Coordenada2D pos_queijo);
void imprimeMatriz (int** m, int w, int h);
Coordenada2D* calculaCaminho (Labirinto* lab, Coordenada2D pos_rato, int* tam);
void mostraCaminho (Labirinto* lab, Coordenada2D pos_queijo, Coordenada2D* caminho, int tam);

/*===========================================================================*/

int main ()
{
    Labirinto* lab; // Um labirinto.
    Coordenada2D* caminho; // Vetor de coordenadas.
    int tam_caminho; // Tamanho do caminho.
    Coordenada2D pos_rato; // Posi��o do rato.
    Coordenada2D pos_queijo; // Posi��o do queijo.

    lab = carregaLabirinto (FILENAME, &pos_rato, &pos_queijo);
    if (!lab)
    {
        printf ("Erro abrindo %s\n", FILENAME);
        return 1;
    }

    preencheMatrizCusto (lab, pos_queijo);
    imprimeMatriz(lab->mat,lab->w,lab->h);

    caminho = calculaCaminho (lab, pos_rato, &tam_caminho);
    mostraCaminho (lab, pos_queijo, caminho, tam_caminho);

    return 0;
    // Desaloca tudo.
    destroiLabirinto (lab);
    free (caminho);

    return 0;
}

/*---------------------------------------------------------------------------*/
/** L� o labirinto de um arquivo txt. Sup�e que est� tudo mais ou menos ok,
 * de acordo com a especifica��o (i.e. n�o estou testando muita coisa...).
 *
 * Par�metros: char* filename: arquivo para abrir.
 *             Coordenada2D* rato: par�metro de sa�da para a posi��o do rato.
 *             Coordenada2D* queijo: idem para a posi��o do queijo.
 *
 * Valor de retorno: ponteiro para uma nova inst�ncia de Labirinto, com a
                     matriz preenchida como explicado na especifica��o. */

Labirinto* carregaLabirinto (char* filename, Coordenada2D* rato, Coordenada2D* queijo)
{
    int i, j;
    char foostring [BUFLEN];
    FILE* f;
    Labirinto* lab;

    f = fopen (filename, "r");
    if (!f)
        return NULL;

    // Inicializa o rato e o queijo.
    rato->x = -1;
    rato->y = -1;
    queijo->x = -1;
    queijo->y = -1;

    // L� a primeira linha.
    if (!fgets (foostring, BUFLEN, f))
        return NULL;

    lab = (Labirinto*) malloc (sizeof (Labirinto)); // Cria o labirinto.
    lab->w = strlen (foostring)-1;
    foostring [lab->w] = 0;

    // Aloca a matriz com um n�mero tempor�rio de linhas.
    lab->mat = (int**) malloc (sizeof (int*) * BUFLEN);

    // Enquanto tiver linhas para ler, vai lendo!
    for (i = 0; foostring [0]; i++)
    {
        // Coloca a linha lida na matriz.
        lab->mat [i] = (int*) malloc (sizeof (int) * lab->w);
        for (j = 0; j < lab->w; j++)
        {
            // Rato? (n�o estou verificando se tem mais que 1 rato!)
            if (foostring [j] == 'r' || foostring [j] == 'R')
            {
                rato->y = i;
                rato->x = j;
                foostring [j] = ' ';
            }
            // Queijo? (n�o estou verificando se tem mais que 1 queijo!)
            else if (foostring [j] == 'q' || foostring [j] == 'Q')
            {
                queijo->y = i;
                queijo->x = j;
                foostring [j] = ' ';
            }

            if (foostring [j] == ' ')
                lab->mat [i][j] = CAMINHO;
            else
                lab->mat [i][j] = PAREDE;
        }

        // L� outra linha. N�o estou testando se est� do tamanho certo!
        if (!fgets (foostring, lab->w + 2, f))
            foostring [0] = 0; // Acabou.
        foostring [lab->w] = 0;
    }

    // Mant�m somente as linhas v�lidas.
    lab->h = i;
    lab->mat = realloc (lab->mat, sizeof (int*) * (lab->h));

    fclose (f);

    return (lab);
}

/*---------------------------------------------------------------------------*/
/** Destruidor para o tipo Labirinto. Desaloca tudo!
 *
 * Par�metros: Labirinto* lab: Labirinto para destruir.
 *
 * Valor de retorno: nenhum. */

void destroiLabirinto (Labirinto* lab)
{
    int i,j;

    for(i=0; i < lab->h; i++)
        for(j = 0; j < lab->w; j++)
            free(lab->mat[i][j]);

    free(lab->h);
    free(lab->w);
    // TODO: escreva esta fun��o!
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto de um jeito "bonitinho".
 *
 * Par�metros: Labirinto* lab: labirinto.
 *             Coordenada2D pos_rato: coordenadas do rato.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. */

void mostraLabirinto (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D pos_queijo)
{
    int i, j;

    for (i = 0; i < lab->h; i++)
    {
        for (j = 0; j < lab->w; j++)
        {
            if (i == pos_rato.y && j == pos_rato.x)
                printf ("R");
            else if (i == pos_queijo.y && j == pos_queijo.x)
                printf ("Q");
            else if (lab->mat [i][j] == PAREDE)
                printf ("|");
            else
                printf (" ");
        }

        printf ("\n");
    }
}

/*---------------------------------------------------------------------------*/
/** Transforma a matriz do labirinto dado em uma matriz de custo. Inicialmente,
 * a matriz cont�m somente os valores definidos pelas constantes PAREDE e
 * CAMINHO, que s�o negativos. A fun��o deve substituir as posi��es contendo o
 * valor para o CAMINHO pela dist�ncia L1 at� a posi��o do queijo.
 *
 * Par�metros: Labirinto* lab: labirinto para atualizar.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. A matriz do labirinto � modificada. */

void preencheMatrizCusto (Labirinto* lab, Coordenada2D pos_queijo)
{
    int k = 0, i, j, tem_menos_um = 0;

    lab->mat[pos_queijo.y][pos_queijo.x] = 0;

    for(i = 0; i < lab->h; i++)
        for(j = 0; j < lab->w; j++)
        {
           if(lab->mat[i][j] == -1)
                tem_menos_um++;
        }

    while (tem_menos_um)
    {
     for(i = 0; i < lab->h; i++)
        for(j = 0; j < lab->w; j++)
        {
            if(lab->mat[i][j] == k)
            {
                if(lab->mat[i+1][j] == CAMINHO)
                {
                    lab->mat[i+1][j] = k + 1;
                    tem_menos_um--;
                }
                if(lab->mat[i-1][j] == CAMINHO)
                {
                    lab->mat[i-1][j] = k + 1;
                    tem_menos_um--;
                }

                if(lab->mat[i][j-1] == CAMINHO)
                {
                    lab->mat[i][j-1] = k + 1;
                    tem_menos_um--;
                }

                if(lab->mat[i][j+1] == CAMINHO)
                {
                    lab->mat[i][j+1] = k + 1;
                    tem_menos_um--;
                }

            }
        }
        k++;
    }


    // TODO: escreva esta fun��o!
}

/*---------------------------------------------------------------------------*/
/** Imprime uma matriz de inteiros na tela.
 *
 * Par�metros: int** m: matriz para mostrar.
 *             int w, int h: largura/altura da matriz.
 *
 * Valor de retorno: nenhum. */

// TODO: apenas leia: esta fun��o pode ser �til para testar alguma coisa. Se precisar, pode mudar o 3 do printf para ver valores maiores.

void imprimeMatriz (int** m, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            printf ("%3d ", m[i][j]);
        printf ("\n");
    }
    printf("\n");
}

/*---------------------------------------------------------------------------*/
/** Gera um vetor que armazena o caminho do rato at� o queijo, com base em uma
 * matriz de custo j� preenchida corretamente. O vetor � gerado com aloca��o
 * din�mica, e deve ser desalocado pelo chamador. Ele deve conter as
 * coordenadas de cada posi��o do caminho, come�ando com a posi��o do rato e
 * terminando com a posi��o do queijo.
 *
 * Par�metros: Labirinto* lab: labirinto com a matriz de custo j� preenchida.
 *             Coordenada2D pos_rato: coordenadas do rato.
 *             int* tam: par�metro de sa�da para o tamanho do caminho (= o
 *               n�mero de valores no vetor que cont�m o caminho).
 *
 * Valor de retorno: o endere�o do vetor alocado na fun��o. */

Coordenada2D* calculaCaminho (Labirinto* lab, Coordenada2D pos_rato, int* tam)
{
    int y = pos_rato.y;
    int x = pos_rato.x;
    Coordenada2D *caminho_ate_queijo;
    int i, k = 0, aux;

    *tam = lab->mat[pos_rato.y][pos_rato.x] + 1;
    aux = *tam;

    caminho_ate_queijo = (Coordenada2D*) malloc (sizeof (Coordenada2D) * aux);

    caminho_ate_queijo[0].y = pos_rato.y;
    caminho_ate_queijo[0].x = pos_rato.x;
    caminho_ate_queijo[1].y = pos_rato.y-1;
    caminho_ate_queijo[1].x = pos_rato.x;
    *tam = 2;

    return caminho_ate_queijo;


    for( i = 0; i < lab->h; i++)
        for(int j = 0; j < lab->w; j++)
        {
            if(lab->mat[i][j] == lab->mat[y][x])
            {
                caminho_ate_queijo[k].x = x;
                caminho_ate_queijo[k].y = y;

                k++;

                if(lab->mat[i+1][j] != PAREDE && lab->mat[i+1][j] < lab->mat[i][j])
                {
                    y = i + 1;
                    x = j;
                }
                //i - 1
                if(lab->mat[i-1][j] != PAREDE && lab->mat[i-1][j] < lab->mat[i][j])
                {
                    y = i - 1;
                    x = j;
                }
                //j + 1
                if(lab->mat[i][j+1] != PAREDE && lab->mat[i][j+1] < lab->mat[i][j])
                {
                    y = i ;
                    x = j + 1;
                }

                //j - 1
                if(lab->mat[i][j-1] != PAREDE && lab->mat[i][j-1] < lab->mat[i][j])
                {
                    y = i;
                    x = j - 1;
                }

            }


        }

    return (caminho_ate_queijo);
    // TODO: escreva esta fun��o!
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto v�rias vezes, percorrendo o caminho.
 *
 * Par�metros: Labirinto* lab: labirinto para mostrar.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *             Coordenada2D* caminho: vetor do caminho.
 *             int tam: tamanho do vetor do caminho.
 *
 * Valor de retorno: nenhum. */

void mostraCaminho (Labirinto* lab, Coordenada2D pos_queijo, Coordenada2D* caminho, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        system (CLEAR);
        mostraLabirinto (lab, caminho [i], pos_queijo);
        //system ("pause");
        getchar();
    }
}

/*===========================================================================*/
