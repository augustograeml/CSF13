#include <stdio.h>

int main()
{
int ano;
float alturaF, alturaB;

alturaF = 150;
alturaB = 110;
ano = 0;

    while (alturaF != alturaB)
    {
    ano++;
    alturaF += 2;
    alturaB += 3;

    }

    printf("Em %d anos Foolano e Barano terao %f centimetros de altura. ", ano, alturaF);



return 0;
}
