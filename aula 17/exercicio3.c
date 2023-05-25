/*-------------------------------
EXERCÍCIO 3 - Aula 17 - 23/05/2023

-------------------------------*/
#include <stdio.h>
#define N 6

int main()
{

   int tabuleiro [N][N] = {{0,0,1,0,0,0},
                            {1,9,9,9,9,9},
                            {0,9,9,9,9,9},
                            {0,9,9,9,9,9},
                            {1,9,9,9,9,9},
                            {1,9,9,9,9,9}};

    int num_pretas = 0, num_brancas = 0, i, j;

    for(i = 1; i < N; i++)
    {
        for(j = 1; j < N; j++)
        {
              if(tabuleiro[i-1][j])
                    num_brancas++;
                else
                    num_pretas++;

                if(tabuleiro[i][j-1])
                    num_brancas++;
                else
                    num_pretas++;

                if(tabuleiro[i-1][j-1])
                    num_brancas++;
                else
                    num_pretas++;


            if(num_pretas > num_brancas)
                tabuleiro[i][j] = 1;
            else
                tabuleiro[i][j] = 0;

            num_pretas = 0;
            num_brancas = 0;
        }


    }

    for(i=0; i < N; i++)
    {
        for(j=0; j < N; j++)
            printf("%d", tabuleiro[i][j]);

        printf("\n");

    }



return 0;
}
