#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int largura;
    int altura;
    unsigned char** dados;

} GSImage;

GSImage* criaGSImage (int largura, int altura);
void destroiGSImage (GSImage* img);
GSImage* reduzPelaMetade (GSImage* img);

int main()
{
    int largura = 1920, altura = 1080;
    GSImage* img;

    img = criaGSImage(largura, altura);

    destroiGSImage(img);

return 0;
}

GSImage* criaGSImage (int largura, int altura)
{
    GSImage *img;
    int i;

    img = (GSImage*) malloc (sizeof(GSImage)); //aloca memória para a pilha

    img->altura = altura;
    img->largura = largura;

    img->dados = (unsigned char**) malloc (altura * sizeof(unsigned char*));
    for (i = 0; i < altura; i++)
        img->dados[i] = (unsigned char*) malloc (largura * sizeof(unsigned char));

    return img;
}

void destroiGSImage (GSImage* img)
{
    int i;
    for (i = 0; i < img->altura; i++)
        free (img->dados [i]);
    free (img->dados);
    free (img);
}

GSImage* reduzPelaMetade (GSImage* img)
{


}
