/*----------------------
AUGUSTO CESAR GRAEML - AULA 19
EXERCICIO 1
TRIANGULO DE PASCAL
----------------------*/
#include <stdio.h>
#include <stdlib.h>
#define GRAU 7

int** geraTrianguloDePascal (int grau);
void destroiTrianguloDePascal (int** t, int grau);

int main ()
{
    int grau = 7;
    int i, j;
    int** mat = geraTrianguloDePascal(grau);

    for(i = 0; i < grau; i++)
    {
        for(j = 0; j < grau; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    destroiTrianguloDePascal(mat, grau);


return 0;
}

int** geraTrianguloDePascal (int grau)
{
 int i, j;

 int** mat = (int**) malloc (grau * sizeof (int*));
    for(i = 0; i < grau; i++)
        mat[i] = (int*) malloc (grau*sizeof(int));

    for(i = 1; i < grau; i++)
    {
        for(j = 1; j < grau; j++)
        {
            if(j == 0 || j == i)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
        }
    }




return mat;

}
void destroiTrianguloDePascal (int** t, int grau)
{
    int i;

    for(i = 0; i < grau; i++)
        free(t[i]);

    free(t);


}
